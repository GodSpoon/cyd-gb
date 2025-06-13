// Example usage of SDStorage class
// This file demonstrates how to use the SDStorage class for various operations

#include "hardware/sd_storage.h"
#include <Arduino.h>
#include <vector>
#include <memory>
#include "core/memory_utils.h"

void demonstrateSDStorage() {
    // Create SDStorage instance
    SDStorage storage;
    
    // Initialize the storage
    StorageError result = storage.init();
    if (result != StorageError::SUCCESS) {
        Serial.println("Failed to initialize SD storage");
        return;
    }
    
    Serial.println("SD Storage initialized successfully");
    
    // Example 1: List ROM files
    std::vector<std::string> romFiles;
    result = storage.listFiles("/roms", ".gb", romFiles);
    if (result == StorageError::SUCCESS) {
        Serial.printf("Found %d ROM files:\n", romFiles.size());
        for (const auto& file : romFiles) {
            Serial.printf("  - %s\n", file.c_str());
        }
    }
    
    // Example 2: Read a configuration file
    const char* configPath = "/config.txt";
    if (storage.exists(configPath)) {
        size_t configSize = storage.getFileSize(configPath);
        if (configSize > 0 && configSize < 1024) { // Reasonable config file size
            auto configBuffer = make_unique<uint8_t[]>(configSize);
            size_t readSize = configSize;
            
            result = storage.readFile(configPath, configBuffer.get(), readSize);
            if (result == StorageError::SUCCESS) {
                Serial.printf("Read configuration: %.*s\n", readSize, configBuffer.get());
            }
        }
    }
    
    // Example 3: Write a save state
    const char* saveStatePath = "/saves/game1.sav";
    const char* saveData = "example save state data";
    size_t saveDataSize = strlen(saveData);
    
    result = storage.writeFile(saveStatePath, 
                              reinterpret_cast<const uint8_t*>(saveData), 
                              saveDataSize);
    if (result == StorageError::SUCCESS) {
        Serial.printf("Save state written successfully to %s\n", saveStatePath);
    }
    
    // Example 4: Create a directory for saves
    result = storage.createDirectory("/saves");
    if (result == StorageError::SUCCESS) {
        Serial.println("Saves directory created");
    }
    
    // Example 5: Get storage information
    if (storage.isInitialized()) {
        uint64_t cardSize = storage.getCardSize();
        uint8_t cardType = storage.getCardType();
        
        Serial.printf("SD Card Info - Size: %llu bytes, Type: %d\n", cardSize, cardType);
    }
}

// Example error handling function
void handleStorageError(StorageError error, const char* operation) {
    Serial.printf("Storage operation '%s' failed: ", operation);
    
    switch (error) {
        case StorageError::SUCCESS:
            Serial.println("Success (no error)");
            break;
        case StorageError::INIT_FAILED:
            Serial.println("Initialization failed");
            break;
        case StorageError::FILE_NOT_FOUND:
            Serial.println("File not found");
            break;
        case StorageError::READ_ERROR:
            Serial.println("Read error");
            break;
        case StorageError::WRITE_ERROR:
            Serial.println("Write error");
            break;
        case StorageError::INSUFFICIENT_SPACE:
            Serial.println("Insufficient space");
            break;
        default:
            Serial.println("Unknown error");
            break;
    }
}
