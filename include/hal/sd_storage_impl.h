#ifndef SD_STORAGE_IMPL_H
#define SD_STORAGE_IMPL_H

#include "hal/storage_interface.h"
#include <SD.h>
#include <Arduino.h>

/**
 * Concrete implementation of IStorage interface using SD library
 * This class wraps the SD card functionality to conform to the HAL interface
 */
class SDStorageImpl : public IStorage {
private:
    bool initialized = false;
    
    // Helper methods
    StorageError convertFileError();
    bool isValidPath(const char* path);

public:
    SDStorageImpl() = default;
    virtual ~SDStorageImpl() = default;

    // IStorage interface implementation
    StorageError init() override;
    StorageError listFiles(const char* path, const char* extension, std::vector<std::string>& files) override;
    StorageError readFile(const char* path, uint8_t* buffer, size_t& size) override;
    StorageError writeFile(const char* path, const uint8_t* buffer, size_t size) override;
    bool exists(const char* path) override;
    size_t getFileSize(const char* path) override;

    // Additional methods
    bool isInitialized() const { return initialized; }
    uint64_t getCardSize() const;
    uint8_t getCardType() const;
};

#endif // SD_STORAGE_IMPL_H
