#ifndef CORE_RESULT_H
#define CORE_RESULT_H

#include <cstdint>
#include <type_traits>
#include <utility>  // For std::move

// Emulator-specific error codes
enum class EmulatorError : uint8_t {
    SUCCESS = 0,
    ROM_LOAD_FAILED,
    DISPLAY_INIT_FAILED,
    TOUCH_INIT_FAILED,
    SD_CARD_ERROR,
    MEMORY_ALLOCATION_FAILED,
    MEMORY_EXHAUSTED,
    INVALID_STATE,
    HARDWARE_ERROR,
    MEMORY_ERROR
};

// Forward declaration for specialization
template<typename T>
class Result;

// Primary Result<T> template class
template<typename T>
class Result {
private:
    bool is_success;
    union {
        T value;
        EmulatorError error_code;
    };

public:
    // Constructors (private to enforce factory pattern)
    explicit Result(T&& val) : is_success(true), value(std::move(val)) {}
    explicit Result(const T& val) : is_success(true), value(val) {}
    explicit Result(EmulatorError err) : is_success(false), error_code(err) {}

    // Move constructor
    Result(Result&& other) noexcept : is_success(other.is_success) {
        if (is_success) {
            new (&value) T(std::move(other.value));
        } else {
            error_code = other.error_code;
        }
    }

    // Copy constructor
    Result(const Result& other) : is_success(other.is_success) {
        if (is_success) {
            new (&value) T(other.value);
        } else {
            error_code = other.error_code;
        }
    }

    // Destructor
    ~Result() {
        if (is_success) {
            value.~T();
        }
    }

    // Assignment operators
    Result& operator=(Result&& other) noexcept {
        if (this != &other) {
            if (is_success) {
                value.~T();
            }
            is_success = other.is_success;
            if (is_success) {
                new (&value) T(std::move(other.value));
            } else {
                error_code = other.error_code;
            }
        }
        return *this;
    }

    Result& operator=(const Result& other) {
        if (this != &other) {
            if (is_success) {
                value.~T();
            }
            is_success = other.is_success;
            if (is_success) {
                new (&value) T(other.value);
            } else {
                error_code = other.error_code;
            }
        }
        return *this;
    }

    // Factory methods
    static Result<T> ok(T&& val) {
        return Result<T>(std::move(val));
    }

    static Result<T> ok(const T& val) {
        return Result<T>(val);
    }

    static Result<T> err(EmulatorError error) {
        return Result<T>(error);
    }

    // Query methods
    bool is_ok() const {
        return is_success;
    }

    bool is_err() const {
        return !is_success;
    }

    // Value extraction
    T unwrap() const {
        if (!is_success) {
            // In embedded systems, we can't throw exceptions
            // This is a critical error that should be caught during development
            while(1); // Infinite loop to halt execution
        }
        return value;
    }

    T unwrap_or(const T& default_value) const {
        return is_success ? value : default_value;
    }

    EmulatorError error() const {
        if (is_success) {
            // Similar to unwrap(), this should never be called on success
            while(1); // Infinite loop to halt execution
        }
        return error_code;
    }

    // Optional-style operations
    template<typename F>
    auto map(F&& func) -> Result<decltype(func(value))> {
        using ReturnType = decltype(func(value));
        if (is_success) {
            return Result<ReturnType>::ok(func(value));
        } else {
            return Result<ReturnType>::err(error_code);
        }
    }

    template<typename F>
    Result<T> map_err(F&& func) {
        if (is_success) {
            return Result<T>::ok(value);
        } else {
            return Result<T>::err(func(error_code));
        }
    }

    // Boolean conversion for if statements
    explicit operator bool() const {
        return is_success;
    }
};

// Specialization for Result<void>
template<>
class Result<void> {
private:
    bool is_success;
    EmulatorError error_code;

public:
    // Constructors
    explicit Result() : is_success(true), error_code(EmulatorError::SUCCESS) {}
    explicit Result(EmulatorError err) : is_success(false), error_code(err) {}

    // Copy and move constructors
    Result(const Result& other) = default;
    Result(Result&& other) = default;

    // Assignment operators
    Result& operator=(const Result& other) = default;
    Result& operator=(Result&& other) = default;

    // Factory methods
    static Result<void> ok() {
        return Result<void>();
    }

    static Result<void> err(EmulatorError error) {
        return Result<void>(error);
    }

    // Query methods
    bool is_ok() const {
        return is_success;
    }

    bool is_err() const {
        return !is_success;
    }

    // Value extraction
    void unwrap() const {
        if (!is_success) {
            // In embedded systems, we can't throw exceptions
            // This is a critical error that should be caught during development
            while(1); // Infinite loop to halt execution
        }
    }

    EmulatorError error() const {
        if (is_success) {
            // Similar to unwrap(), this should never be called on success
            while(1); // Infinite loop to halt execution
        }
        return error_code;
    }

    // Chaining operations
    template<typename F>
    auto and_then(F&& func) -> decltype(func()) {
        if (is_success) {
            return func();
        } else {
            using ReturnType = decltype(func());
            return ReturnType::err(error_code);
        }
    }

    // Boolean conversion for if statements
    explicit operator bool() const {
        return is_success;
    }
};

// Utility functions for error handling

// Convert EmulatorError to string (useful for debugging)
inline const char* error_to_string(EmulatorError error) {
    switch (error) {
        case EmulatorError::SUCCESS:
            return "SUCCESS";
        case EmulatorError::ROM_LOAD_FAILED:
            return "ROM_LOAD_FAILED";
        case EmulatorError::DISPLAY_INIT_FAILED:
            return "DISPLAY_INIT_FAILED";
        case EmulatorError::TOUCH_INIT_FAILED:
            return "TOUCH_INIT_FAILED";
        case EmulatorError::SD_CARD_ERROR:
            return "SD_CARD_ERROR";
        case EmulatorError::MEMORY_ALLOCATION_FAILED:
            return "MEMORY_ALLOCATION_FAILED";
        case EmulatorError::MEMORY_EXHAUSTED:
            return "MEMORY_EXHAUSTED";
        case EmulatorError::INVALID_STATE:
            return "INVALID_STATE";
        case EmulatorError::HARDWARE_ERROR:
            return "HARDWARE_ERROR";
        case EmulatorError::MEMORY_ERROR:
            return "MEMORY_ERROR";
        default:
            return "UNKNOWN_ERROR";
    }
}

// Macro for early return on error (similar to Rust's ? operator)
#define TRY(result) \
    do { \
        auto _temp_result = (result); \
        if (_temp_result.is_err()) { \
            return decltype(_temp_result)::err(_temp_result.error()); \
        } \
    } while(0)

// Macro for early return on error with value extraction
#define TRY_UNWRAP(var, result) \
    auto _temp_##var = (result); \
    if (_temp_##var.is_err()) { \
        return decltype(_temp_##var)::err(_temp_##var.error()); \
    } \
    auto var = _temp_##var.unwrap()

#endif // CORE_RESULT_H
