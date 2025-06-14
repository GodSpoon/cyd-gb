#include "hal/sd_storage_impl.h"

StorageError SDStorageImpl::init() {
    if (initialized) return StorageError::SUCCESS;
    
    Serial.println("SDStorageImpl: Initializing SD card...");
    
    // Initialize SD card with explicit CS pin
    // From board config: TF_CS=5, uses default SPI pins  
    if (!SD.begin(5)) {  // CS pin 5
        Serial.println("SDStorageImpl: SD card initialization failed");
        return StorageError::INIT_FAILED;
    }
    
    // Verify card is accessible
    uint8_t cardType = SD.cardType();
    if (cardType == CARD_NONE) {
        Serial.println("SDStorageImpl: No SD card attached");
        return StorageError::INIT_FAILED;
    }
    
    Serial.print("SDStorageImpl: Card type: ");
    if (cardType == CARD_MMC) Serial.println("MMC");
    else if (cardType == CARD_SD) Serial.println("SDSC");
    else if (cardType == CARD_SDHC) Serial.println("SDHC/SDXC");
    else Serial.println("Unknown");
    
    uint64_t cardSize = SD.cardSize() / (1024 * 1024);
    Serial.printf("SDStorageImpl: Card size: %llu MB\n", cardSize);
    
    initialized = true;
    Serial.println("SDStorageImpl: Initialization complete");
    return StorageError::SUCCESS;
}

StorageError SDStorageImpl::listFiles(const char* path, const char* extension, std::vector<std::string>& files) {
    if (!initialized) return StorageError::INIT_FAILED;
    if (!isValidPath(path)) return StorageError::FILE_NOT_FOUND;
    
    files.clear();
    
    File root = SD.open(path);
    if (!root) {
        Serial.printf("SDStorageImpl: Failed to open directory: %s\n", path);
        return StorageError::FILE_NOT_FOUND;
    }
    
    if (!root.isDirectory()) {
        root.close();
        Serial.printf("SDStorageImpl: Path is not a directory: %s\n", path);
        return StorageError::FILE_NOT_FOUND;
    }
    
    File file = root.openNextFile();
    while (file) {
        if (!file.isDirectory()) {
            String filename = file.name();
            
            // Filter by extension if provided
            if (extension == nullptr || filename.endsWith(extension)) {
                files.push_back(filename.c_str());
            }
        }
        file = root.openNextFile();
    }
    root.close();
    
    Serial.printf("SDStorageImpl: Found %d files in %s\n", files.size(), path);
    return StorageError::SUCCESS;
}

StorageError SDStorageImpl::readFile(const char* path, uint8_t* buffer, size_t& size) {
    if (!initialized) return StorageError::INIT_FAILED;
    if (!isValidPath(path) || !buffer) return StorageError::FILE_NOT_FOUND;
    
    File file = SD.open(path, FILE_READ);
    if (!file) {
        Serial.printf("SDStorageImpl: Failed to open file for reading: %s\n", path);
        return StorageError::FILE_NOT_FOUND;
    }
    
    size_t fileSize = file.size();
    if (fileSize > size) {
        file.close();
        Serial.printf("SDStorageImpl: Buffer too small for file %s (need %d, have %d)\n", 
                     path, fileSize, size);
        return StorageError::INSUFFICIENT_SPACE;
    }
    
    size_t bytesRead = file.read(buffer, fileSize);
    file.close();
    
    if (bytesRead != fileSize) {
        Serial.printf("SDStorageImpl: Partial read of file %s (%d of %d bytes)\n", 
                     path, bytesRead, fileSize);
        return StorageError::READ_ERROR;
    }
    
    size = bytesRead;
    Serial.printf("SDStorageImpl: Successfully read %d bytes from %s\n", size, path);
    return StorageError::SUCCESS;
}

StorageError SDStorageImpl::writeFile(const char* path, const uint8_t* buffer, size_t size) {
    if (!initialized) return StorageError::INIT_FAILED;
    if (!isValidPath(path) || !buffer) return StorageError::FILE_NOT_FOUND;
    
    File file = SD.open(path, FILE_WRITE);
    if (!file) {
        Serial.printf("SDStorageImpl: Failed to open file for writing: %s\n", path);
        return StorageError::WRITE_ERROR;
    }
    
    size_t bytesWritten = file.write(buffer, size);
    file.close();
    
    if (bytesWritten != size) {
        Serial.printf("SDStorageImpl: Partial write to file %s (%d of %d bytes)\n", 
                     path, bytesWritten, size);
        return StorageError::WRITE_ERROR;
    }
    
    Serial.printf("SDStorageImpl: Successfully wrote %d bytes to %s\n", size, path);
    return StorageError::SUCCESS;
}

bool SDStorageImpl::exists(const char* path) {
    if (!initialized || !isValidPath(path)) return false;
    return SD.exists(path);
}

size_t SDStorageImpl::getFileSize(const char* path) {
    if (!initialized || !isValidPath(path)) return 0;
    
    File file = SD.open(path, FILE_READ);
    if (!file) return 0;
    
    size_t size = file.size();
    file.close();
    return size;
}

uint64_t SDStorageImpl::getCardSize() const {
    if (!initialized) return 0;
    return SD.cardSize();
}

uint8_t SDStorageImpl::getCardType() const {
    if (!initialized) return CARD_NONE;
    return SD.cardType();
}

StorageError SDStorageImpl::convertFileError() {
    // This is a simplified error conversion
    // In a more sophisticated implementation, we could check errno or other error indicators
    return StorageError::READ_ERROR;
}

bool SDStorageImpl::isValidPath(const char* path) {
    return path != nullptr && strlen(path) > 0;
}
