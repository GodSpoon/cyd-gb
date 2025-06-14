#include "hardware/sd_storage.h"
#include <Arduino.h>

// FileHandle implementation (RAII wrapper for File objects)
SDStorage::FileHandle::FileHandle(const char* path, const char* mode) : valid(false) {
    if (!path || !mode) {
        Serial.println("SDStorage::FileHandle: Invalid path or mode");
        return;
    }
    
    if (strcmp(mode, "r") == 0) {
        file = SD.open(path, FILE_READ);
    } else if (strcmp(mode, "w") == 0) {
        file = SD.open(path, FILE_WRITE);
    } else {
        Serial.printf("SDStorage::FileHandle: Unsupported mode: %s\n", mode);
        return;
    }
    
    valid = file ? true : false;
    if (!valid) {
        Serial.printf("SDStorage::FileHandle: Failed to open file: %s\n", path);
    }
}

SDStorage::FileHandle::~FileHandle() {
    if (valid && file) {
        file.close();
    }
}

SDStorage::FileHandle::FileHandle(FileHandle&& other) noexcept 
    : file(std::move(other.file)), valid(other.valid) {
    other.valid = false;
}

SDStorage::FileHandle& SDStorage::FileHandle::operator=(FileHandle&& other) noexcept {
    if (this != &other) {
        if (valid && file) {
            file.close();
        }
        file = std::move(other.file);
        valid = other.valid;
        other.valid = false;
    }
    return *this;
}

size_t SDStorage::FileHandle::size() const {
    return valid ? file.size() : 0;
}

size_t SDStorage::FileHandle::read(uint8_t* buffer, size_t size) {
    return valid ? file.read(buffer, size) : 0;
}

size_t SDStorage::FileHandle::write(const uint8_t* buffer, size_t size) {
    return valid ? file.write(buffer, size) : 0;
}

// SDStorage implementation
StorageError SDStorage::init() {
    if (initialized) {
        Serial.println("SDStorage: Already initialized");
        return StorageError::SUCCESS;
    }
    
    Serial.println("SDStorage: Initializing SD card...");
    
    // Reconfigure SPI for SD card pins (touch may have changed it)
    // From board config: TF uses MOSI=23, MISO=19, SCLK=18
    Serial.println("SDStorage: Reconfiguring SPI for SD card (SCLK=18, MISO=19, MOSI=23)");
    SPI.end(); // End any existing SPI configuration
    SPI.begin(18, 19, 23);  // SD card pins: SCLK, MISO, MOSI
    
    // Initialize SD card with explicit CS pin
    // From board config: TF_CS=5, uses default SPI pins
    if (!SD.begin(5)) {  // CS pin 5
        Serial.println("SDStorage: SD card initialization failed");
        return StorageError::INIT_FAILED;
    }
    
    // Verify card is accessible
    uint8_t cardType = SD.cardType();
    if (cardType == CARD_NONE) {
        Serial.println("SDStorage: No SD card attached");
        return StorageError::INIT_FAILED;
    }
    
    // Log card information
    Serial.print("SDStorage: Card type: ");
    switch (cardType) {
        case CARD_MMC:
            Serial.println("MMC");
            break;
        case CARD_SD:
            Serial.println("SDSC");
            break;
        case CARD_SDHC:
            Serial.println("SDHC/SDXC");
            break;
        default:
            Serial.println("Unknown");
            break;
    }
    
    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SDStorage: Card size: %llu MB\n", cardSize);
    
    initialized = true;
    Serial.println("SDStorage: Initialization complete");
    return StorageError::SUCCESS;
}

StorageError SDStorage::listFiles(const char* path, const char* extension, std::vector<std::string>& files) {
    if (!initialized) {
        Serial.println("SDStorage: Not initialized");
        return StorageError::INIT_FAILED;
    }
    
    if (!isValidPath(path)) {
        Serial.println("SDStorage: Invalid path for listing");
        return StorageError::FILE_NOT_FOUND;
    }
    
    files.clear();
    return processDirectory(path, extension, files);
}

StorageError SDStorage::readFile(const char* path, uint8_t* buffer, size_t& size) {
    if (!initialized) {
        Serial.println("SDStorage: Not initialized");
        return StorageError::INIT_FAILED;
    }
    
    if (!isValidPath(path) || !buffer) {
        Serial.println("SDStorage: Invalid parameters for read operation");
        return StorageError::FILE_NOT_FOUND;
    }
    
    // Use RAII FileHandle for automatic resource cleanup
    FileHandle fileHandle(path, "r");
    if (!fileHandle.isValid()) {
        Serial.printf("SDStorage: Failed to open file for reading: %s\n", path);
        return StorageError::FILE_NOT_FOUND;
    }
    
    size_t fileSize = fileHandle.size();
    if (fileSize > size) {
        Serial.printf("SDStorage: Buffer too small for file %s (need %d, have %d)\n", 
                     path, fileSize, size);
        return StorageError::INSUFFICIENT_SPACE;
    }
    
    size_t bytesRead = fileHandle.read(buffer, fileSize);
    if (bytesRead != fileSize) {
        Serial.printf("SDStorage: Partial read of file %s (%d of %d bytes)\n", 
                     path, bytesRead, fileSize);
        return StorageError::READ_ERROR;
    }
    
    size = bytesRead;
    Serial.printf("SDStorage: Successfully read %d bytes from %s\n", size, path);
    return StorageError::SUCCESS;
}

StorageError SDStorage::writeFile(const char* path, const uint8_t* buffer, size_t size) {
    if (!initialized) {
        Serial.println("SDStorage: Not initialized");
        return StorageError::INIT_FAILED;
    }
    
    if (!isValidPath(path) || !buffer) {
        Serial.println("SDStorage: Invalid parameters for write operation");
        return StorageError::FILE_NOT_FOUND;
    }
    
    // Use RAII FileHandle for automatic resource cleanup
    FileHandle fileHandle(path, "w");
    if (!fileHandle.isValid()) {
        Serial.printf("SDStorage: Failed to open file for writing: %s\n", path);
        return StorageError::WRITE_ERROR;
    }
    
    size_t bytesWritten = fileHandle.write(buffer, size);
    if (bytesWritten != size) {
        Serial.printf("SDStorage: Partial write to file %s (%d of %d bytes)\n", 
                     path, bytesWritten, size);
        return StorageError::WRITE_ERROR;
    }
    
    Serial.printf("SDStorage: Successfully wrote %d bytes to %s\n", size, path);
    return StorageError::SUCCESS;
}

bool SDStorage::exists(const char* path) {
    if (!initialized || !isValidPath(path)) {
        return false;
    }
    return SD.exists(path);
}

size_t SDStorage::getFileSize(const char* path) {
    if (!initialized || !isValidPath(path)) {
        return 0;
    }
    
    FileHandle fileHandle(path, "r");
    return fileHandle.isValid() ? fileHandle.size() : 0;
}

uint64_t SDStorage::getCardSize() const {
    return initialized ? SD.cardSize() : 0;
}

uint8_t SDStorage::getCardType() const {
    return initialized ? SD.cardType() : CARD_NONE;
}

StorageError SDStorage::createDirectory(const char* path) {
    if (!initialized) {
        return StorageError::INIT_FAILED;
    }
    
    if (!isValidPath(path)) {
        return StorageError::FILE_NOT_FOUND;
    }
    
    if (!SD.mkdir(path)) {
        Serial.printf("SDStorage: Failed to create directory: %s\n", path);
        return StorageError::WRITE_ERROR;
    }
    
    Serial.printf("SDStorage: Successfully created directory: %s\n", path);
    return StorageError::SUCCESS;
}

StorageError SDStorage::deleteFile(const char* path) {
    if (!initialized) {
        return StorageError::INIT_FAILED;
    }
    
    if (!isValidPath(path)) {
        return StorageError::FILE_NOT_FOUND;
    }
    
    if (!SD.remove(path)) {
        Serial.printf("SDStorage: Failed to delete file: %s\n", path);
        return StorageError::WRITE_ERROR;
    }
    
    Serial.printf("SDStorage: Successfully deleted file: %s\n", path);
    return StorageError::SUCCESS;
}

// Helper methods
bool SDStorage::isValidPath(const char* path) const {
    return path != nullptr && strlen(path) > 0;
}

bool SDStorage::hasExtension(const char* filename, const char* extension) const {
    if (!filename || !extension) {
        return false;
    }
    
    // If no extension filter specified, include all files
    if (strlen(extension) == 0) {
        return true;
    }
    
    const char* fileExt = strrchr(filename, '.');
    if (!fileExt) {
        return false;
    }
    
    // Compare extensions (case-insensitive)
    return strcasecmp(fileExt, extension) == 0;
}

StorageError SDStorage::processDirectory(const char* path, const char* extension, std::vector<std::string>& files) {
    File dir = SD.open(path);
    if (!dir) {
        Serial.printf("SDStorage: Failed to open directory: %s\n", path);
        return StorageError::FILE_NOT_FOUND;
    }
    
    if (!dir.isDirectory()) {
        dir.close();
        Serial.printf("SDStorage: Path is not a directory: %s\n", path);
        return StorageError::FILE_NOT_FOUND;
    }
    
    File entry = dir.openNextFile();
    while (entry) {
        if (!entry.isDirectory()) {
            const char* filename = entry.name();
            if (hasExtension(filename, extension)) {
                files.emplace_back(filename);
                Serial.printf("SDStorage: Found file: %s\n", filename);
            }
        }
        entry.close();
        entry = dir.openNextFile();
    }
    
    dir.close();
    Serial.printf("SDStorage: Found %d files in %s\n", files.size(), path);
    return StorageError::SUCCESS;
}
