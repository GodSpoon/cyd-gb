#ifndef STORAGE_INTERFACE_H
#define STORAGE_INTERFACE_H

#include <cstdint>
#include <vector>
#include <string>

enum class StorageError {
    SUCCESS,
    INIT_FAILED,
    FILE_NOT_FOUND,
    READ_ERROR,
    WRITE_ERROR,
    INSUFFICIENT_SPACE
};

class IStorage {
public:
    virtual ~IStorage() = default;
    virtual StorageError init() = 0;
    virtual StorageError listFiles(const char* path, const char* extension, std::vector<std::string>& files) = 0;
    virtual StorageError readFile(const char* path, uint8_t* buffer, size_t& size) = 0;
    virtual StorageError writeFile(const char* path, const uint8_t* buffer, size_t size) = 0;
    virtual bool exists(const char* path) = 0;
    virtual size_t getFileSize(const char* path) = 0;
};

#endif
