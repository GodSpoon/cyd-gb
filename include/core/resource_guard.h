#ifndef CORE_RESOURCE_GUARD_H
#define CORE_RESOURCE_GUARD_H

#include <functional>
#include <utility>
#include <cstddef>

// Forward declarations
template<typename T>
class MemoryGuard;

/**
 * @brief RAII resource guard that executes a cleanup function on destruction
 * 
 * ResourceGuard provides automatic resource cleanup using RAII principles.
 * It takes a cleanup function in the constructor and calls it in the destructor,
 * unless release() has been called to disable cleanup.
 * 
 * Example usage:
 * ```cpp
 * auto guard = ResourceGuard([&]() { 
 *     Serial.println("Cleaning up resource"); 
 *     closeFile(); 
 * });
 * // Resource will be cleaned up when guard goes out of scope
 * ```
 */
class ResourceGuard {
private:
    std::function<void()> cleanup_func;
    bool active;

public:
    /**
     * @brief Construct a ResourceGuard with a cleanup function
     * @param cleanup Function to call on destruction
     */
    explicit ResourceGuard(std::function<void()> cleanup) 
        : cleanup_func(std::move(cleanup)), active(true) {}

    /**
     * @brief Destructor - calls cleanup function if still active
     */
    ~ResourceGuard() {
        if (active && cleanup_func) {
            cleanup_func();
        }
    }

    // Move-only semantics (no copy allowed)
    ResourceGuard(const ResourceGuard&) = delete;
    ResourceGuard& operator=(const ResourceGuard&) = delete;

    /**
     * @brief Move constructor
     * @param other ResourceGuard to move from
     */
    ResourceGuard(ResourceGuard&& other) noexcept 
        : cleanup_func(std::move(other.cleanup_func)), active(other.active) {
        other.active = false;
    }

    /**
     * @brief Move assignment operator
     * @param other ResourceGuard to move from
     * @return Reference to this ResourceGuard
     */
    ResourceGuard& operator=(ResourceGuard&& other) noexcept {
        if (this != &other) {
            // Clean up current resource if active
            if (active && cleanup_func) {
                cleanup_func();
            }
            
            cleanup_func = std::move(other.cleanup_func);
            active = other.active;
            other.active = false;
        }
        return *this;
    }

    /**
     * @brief Release the guard - disables cleanup on destruction
     * @return True if the guard was active before release, false otherwise
     */
    bool release() {
        bool was_active = active;
        active = false;
        return was_active;
    }

    /**
     * @brief Check if the guard is still active
     * @return True if cleanup will be called on destruction, false otherwise
     */
    bool is_active() const {
        return active;
    }

    /**
     * @brief Manually trigger cleanup and deactivate the guard
     * 
     * This allows explicit cleanup before destruction.
     * After calling this, the destructor will not call cleanup again.
     */
    void reset() {
        if (active && cleanup_func) {
            cleanup_func();
            active = false;
        }
    }
};

/**
 * @brief RAII memory guard for array allocation management
 * 
 * MemoryGuard manages dynamic array allocation using new T[count] and 
 * automatically calls delete[] on destruction. It's designed for embedded
 * systems where manual memory management is critical.
 * 
 * Example usage:
 * ```cpp
 * auto buffer = MemoryGuard<uint8_t>(1024);  // Allocates uint8_t[1024]
 * uint8_t* data = buffer.get();
 * // Memory is automatically freed when buffer goes out of scope
 * ```
 */
template<typename T>
class MemoryGuard {
private:
    T* ptr;
    size_t count;
    bool active;

public:
    /**
     * @brief Construct MemoryGuard and allocate array
     * @param element_count Number of elements to allocate
     */
    explicit MemoryGuard(size_t element_count) 
        : ptr(nullptr), count(element_count), active(true) {
        if (element_count > 0) {
            ptr = new T[element_count]();  // Zero-initialize
        }
    }

    /**
     * @brief Construct MemoryGuard from existing pointer (takes ownership)
     * @param existing_ptr Pointer to take ownership of
     * @param element_count Number of elements the pointer represents
     */
    MemoryGuard(T* existing_ptr, size_t element_count) 
        : ptr(existing_ptr), count(element_count), active(true) {}

    /**
     * @brief Destructor - frees allocated memory if still active
     */
    ~MemoryGuard() {
        if (active && ptr) {
            delete[] ptr;
        }
    }

    // Move-only semantics (no copy allowed)
    MemoryGuard(const MemoryGuard&) = delete;
    MemoryGuard& operator=(const MemoryGuard&) = delete;

    /**
     * @brief Move constructor
     * @param other MemoryGuard to move from
     */
    MemoryGuard(MemoryGuard&& other) noexcept 
        : ptr(other.ptr), count(other.count), active(other.active) {
        other.ptr = nullptr;
        other.active = false;
    }

    /**
     * @brief Move assignment operator
     * @param other MemoryGuard to move from
     * @return Reference to this MemoryGuard
     */
    MemoryGuard& operator=(MemoryGuard&& other) noexcept {
        if (this != &other) {
            // Clean up current memory if active
            if (active && ptr) {
                delete[] ptr;
            }
            
            ptr = other.ptr;
            count = other.count;
            active = other.active;
            
            other.ptr = nullptr;
            other.active = false;
        }
        return *this;
    }

    /**
     * @brief Get pointer to managed memory
     * @return Pointer to the allocated array, or nullptr if not allocated
     */
    T* get() const {
        return ptr;
    }

    /**
     * @brief Get pointer to managed memory (alias for get())
     * @return Pointer to the allocated array, or nullptr if not allocated
     */
    T* data() const {
        return ptr;
    }

    /**
     * @brief Get number of elements in the array
     * @return Number of elements allocated
     */
    size_t size() const {
        return count;
    }

    /**
     * @brief Check if memory is allocated and guard is active
     * @return True if memory is allocated and will be freed on destruction
     */
    bool is_valid() const {
        return active && ptr != nullptr;
    }

    /**
     * @brief Release ownership of the memory - disables cleanup on destruction
     * @return Pointer to the memory that is no longer managed
     */
    T* release() {
        T* temp = ptr;
        ptr = nullptr;
        active = false;
        return temp;
    }

    /**
     * @brief Manually free memory and deactivate the guard
     * 
     * This allows explicit cleanup before destruction.
     * After calling this, the destructor will not free memory again.
     */
    void reset() {
        if (active && ptr) {
            delete[] ptr;
            ptr = nullptr;
            active = false;
        }
    }

    /**
     * @brief Replace managed memory with new allocation
     * @param element_count Number of elements to allocate
     */
    void reset(size_t element_count) {
        // Free existing memory
        if (active && ptr) {
            delete[] ptr;
        }
        
        // Allocate new memory
        count = element_count;
        active = true;
        if (element_count > 0) {
            ptr = new T[element_count]();  // Zero-initialize
        } else {
            ptr = nullptr;
        }
    }

    /**
     * @brief Array subscript operator
     * @param index Index of element to access
     * @return Reference to element at index
     */
    T& operator[](size_t index) {
        return ptr[index];
    }

    /**
     * @brief Const array subscript operator
     * @param index Index of element to access
     * @return Const reference to element at index
     */
    const T& operator[](size_t index) const {
        return ptr[index];
    }

    /**
     * @brief Boolean conversion operator
     * @return True if memory is allocated and guard is active
     */
    explicit operator bool() const {
        return is_valid();
    }

    /**
     * @brief Arrow operator for accessing pointer members
     * @return Pointer to managed memory
     */
    T* operator->() const {
        return ptr;
    }

    /**
     * @brief Dereference operator
     * @return Reference to first element
     */
    T& operator*() const {
        return *ptr;
    }
};

// Convenience factory functions

/**
 * @brief Create a ResourceGuard with a lambda cleanup function
 * @param cleanup Cleanup function to execute on destruction
 * @return ResourceGuard managing the cleanup function
 */
inline ResourceGuard make_resource_guard(std::function<void()> cleanup) {
    return ResourceGuard(std::move(cleanup));
}

/**
 * @brief Create a MemoryGuard for array allocation
 * @tparam T Type of elements to allocate
 * @param count Number of elements to allocate
 * @return MemoryGuard managing the allocated array
 */
template<typename T>
MemoryGuard<T> make_memory_guard(size_t count) {
    return MemoryGuard<T>(count);
}

/**
 * @brief Create a MemoryGuard from existing pointer (takes ownership)
 * @tparam T Type of elements
 * @param ptr Pointer to take ownership of
 * @param count Number of elements the pointer represents
 * @return MemoryGuard managing the existing pointer
 */
template<typename T>
MemoryGuard<T> make_memory_guard(T* ptr, size_t count) {
    return MemoryGuard<T>(ptr, count);
}

#endif // CORE_RESOURCE_GUARD_H
