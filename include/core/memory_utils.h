#ifndef CORE_MEMORY_UTILS_H
#define CORE_MEMORY_UTILS_H

#include <memory>
#include <utility>
#include <type_traits>

// ESP32 Arduino framework compatibility layer for C++14 features
// The ESP32 Arduino framework doesn't always expose std::make_unique even with -std=c++14

namespace esp32_compat {

#if __cplusplus >= 201402L && defined(__cpp_lib_make_unique)
    // Use standard library version if available
    using std::make_unique;
#else
    // Custom implementation for ESP32 Arduino framework compatibility
    template<typename T, typename... Args>
    typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type
    make_unique(Args&&... args) {
        return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
    }
    
    // Specialization for arrays with known bounds (disabled)
    template<typename T, typename... Args>
    typename std::enable_if<std::is_array<T>::value && std::extent<T>::value != 0, void>::type
    make_unique(Args&&...) = delete;
    
    // Specialization for arrays with unknown bounds
    template<typename T>
    typename std::enable_if<std::is_array<T>::value && std::extent<T>::value == 0, std::unique_ptr<T>>::type
    make_unique(std::size_t size) {
        using U = typename std::remove_extent<T>::type;
        return std::unique_ptr<T>(new U[size]());
    }
#endif

} // namespace esp32_compat

// For convenience, bring into global namespace with clear prefix
using esp32_compat::make_unique;

#endif // CORE_MEMORY_UTILS_H
