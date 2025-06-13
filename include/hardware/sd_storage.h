#ifndef SD_STORAGE_H
#define SD_STORAGE_H

#include "hal/storage_interface.h"
#include <SD.h>
#include <Arduino.h>
#include <memory>

/**
 * SDStorage class implementing IStorage interface for SD card operations
 * 
 * This class provides a hardware-specific implementation of storage operations
 * using the ESP32 SD library. It follows RAII principles for resource management
 * and provides comprehensive error handling.
 * 
 * Features:
 * - Automatic SD card initialization with SD.begin()
 * - Directory listing with file extension filtering
 * - Safe file read/write operations with proper error handling
 * - RAII-based File object management
 * - Comprehensive error reporting via StorageError enum
 */
class SDStorage : public IStorage {
private:
    bool initialized = false;
    
    // Helper class for RAII File management
    class FileHandle {
    private:
        File file;
        bool valid;
        
    public:
        FileHandle(const char* path, const char* mode);
        ~FileHandle();
        
        // Move semantics only (no copying)
        FileHandle(const FileHandle&) = delete;
        FileHandle& operator=(const FileHandle&) = delete;
        FileHandle(FileHandle&& other) noexcept;
        FileHandle& operator=(FileHandle&& other) noexcept;
        
        bool isValid() const { return valid; }
        File& get() { return file; }
        size_t size() const;
        size_t read(uint8_t* buffer, size_t size);
        size_t write(const uint8_t* buffer, size_t size);
    };
    
    // Helper methods
    bool isValidPath(const char* path) const;
    bool hasExtension(const char* filename, const char* extension) const;
    StorageError processDirectory(const char* path, const char* extension, std::vector<std::string>& files);
    
public:
    SDStorage() = default;
    virtual ~SDStorage() = default;
    
    // Disable copy constructor and assignment operator
    SDStorage(const SDStorage&) = delete;
    SDStorage& operator=(const SDStorage&) = delete;
    
    // IStorage interface implementation
    StorageError init() override;
    StorageError listFiles(const char* path, const char* extension, std::vector<std::string>& files) override;
    StorageError readFile(const char* path, uint8_t* buffer, size_t& size) override;
    StorageError writeFile(const char* path, const uint8_t* buffer, size_t size) override;
    bool exists(const char* path) override;
    size_t getFileSize(const char* path) override;
    
    // Additional utility methods
    bool isInitialized() const { return initialized; }
    uint64_t getCardSize() const;
    uint8_t getCardType() const;
    StorageError createDirectory(const char* path);
    StorageError deleteFile(const char* path);
};

#endif // SD_STORAGE_H
