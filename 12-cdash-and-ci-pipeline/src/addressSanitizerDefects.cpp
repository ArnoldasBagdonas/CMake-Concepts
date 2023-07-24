// addressSanitizerDefects.cpp

// AddressSanitizer (ASan) is a dynamic analysis tool  that can detect various memory-related defects
// in C++ code, such as buffer overflows, use-after-free, and memory leaks.

#include "addressSanitizerDefects/addressSanitizerDefects.hpp"

#include <iostream>
#include <cstring>
#include <limits.h>

namespace addressSanitizer
{
    // Function with a buffer overflow defect
    void bufferOverflow() {
        int arr[5];
        for (int i = 0; i <= 5; ++i) { // Out of bounds access, causing buffer overflow
            arr[i] = i;
        }
    }

    // Function with a use-after-free defect
    void useAfterFree() {
        int* ptr = new int;
        delete ptr;
        *ptr = 10; // Using the deleted pointer, which leads to use-after-free
    }

    // Function with a memory leak defect
    void memoryLeak() {
        int* ptr = new int;
        // The memory allocated is not freed, causing a memory leak
    }

    // Function with uninitialized variable defect
    void uninitializedVariable() {
        int x;
        std::cout << x << std::endl; // Using uninitialized variable
    }

    // Function with uninitialized memory reads
    int uninitializedMemory(int argc) {
        int a[2];
        if (a[argc != 1])
            return 1;
        else
            return 0;
    }
    void uninitializedMemoryReads() {
        
        std::cout << uninitializedMemory(10) << std::endl; // Using uninitialized variable read
    }
    

    // Function with division by zero defect
    void divisionByZero() {
        int a = 10;
        int b = 0;
        int result = a / b; // Division by zero
        std::cout << result << std::endl; // This line will not be executed
    }

    // Function with null pointer dereference defect
    void nullPointerDereference() {
        int* ptr = nullptr;
        *ptr = 5; // Dereferencing a null pointer
    }

    // Function with mismatched delete defect
    void mismatchedDelete() {
        int* ptr = new int;
        delete[] ptr; // Deleting using delete[] instead of delete
    }

    // Function with a dangling pointer defect
    int* danglingPointer() {
        int value = 10;
        return &value; // Returning a pointer to a local variable, causing a dangling pointer
    }

    // Function with a stack address escape defect
    int* stackAddressEscape() {
        int stackVar = 5;
        return &stackVar; // Returning a pointer to a stack variable, causing stack address escape
    }

    // Function with a use of a stale pointer defect
    void useOfStalePointer() {
        int* ptr = new int;
        delete ptr;
        int x = *ptr; // Using a deleted pointer, which leads to a use-after-free error
    }

    // Function with a write to read-only memory defect
    void writeToReadOnlyMemory() {
        char* str = "Hello";
        str[0] = 'h'; // Writing to a read-only memory (string literal)
    }

    // Function with a buffer overflow in memcpy defect
    void bufferOverflowInMemcpy() {
        char src[6] = "Hello";
        char dest[3];
        std::memcpy(dest, src, sizeof(src)); // Buffer overflow in memcpy
    }

    // Function with a buffer overflow in strncpy defect
    void bufferOverflowInStrncpy() {
        char src[6] = "Hello";
        char dest[3];
        std::strncpy(dest, src, sizeof(dest)); // Buffer overflow in strncpy
    }

    // Function with a buffer overflow in sprintf defect
    void bufferOverflowInSprintf() {
        char buffer[10];
        std::sprintf(buffer, "%s", "This is a long string that overflows the buffer"); // Buffer overflow in sprintf
    }

    // Function with a buffer overflow in sscanf defect
    void bufferOverflowInSscanf() {
        char buffer[10];
        std::sprintf(buffer, "%s", "1234567890"); // Filling buffer with data
        int num;
        std::sscanf(buffer, "%d", &num); // Buffer overflow in sscanf
    }

    // Function with a buffer overflow in snprintf defect
    void bufferOverflowInSnprintf() {
        char buffer[10];
        std::snprintf(buffer, sizeof(buffer), "%s", "This is a long string that overflows the buffer"); // Buffer overflow in snprintf
    }

    // Function with a memory leak in a loop defect
    void memoryLeakInLoop() {
        for (int i = 0; i < 10; ++i) {
            int* ptr = new int;
            // The memory allocated in each iteration is not freed, causing a memory leak
        }
    }

    // Function with a use of a freed pointer defect
    void useOfFreedPointer() {
        int* ptr = new int;
        delete ptr;
        std::cout << *ptr << std::endl; // Using a deleted pointer, which leads to a use-after-free error
    }

    // Function with a buffer underflow defect
    void bufferUnderflow() {
        char buffer[6] = "Hello";
        int index = -1;
        char ch = buffer[index]; // Buffer underflow
    }

    // Function with a buffer under-read defect
    void bufferUnderRead() {
        char buffer[6] = "Hello";
        char ch = buffer[10]; // Buffer under-read
    }

    // Function with a use of a null pointer defect
    void useOfNullPointer() {
        int* ptr = nullptr;
        std::cout << *ptr << std::endl; // Using a null pointer, which leads to a null pointer dereference error
    }

    // Function with a missing return statement defect
    int missingReturnStatement() {
        // Missing return statement, this should return an integer value
    }

    // Function with an incorrect pointer arithmetic defect
    void incorrectPointerArithmetic() {
        int arr[] = {1, 2, 3, 4, 5};
        int* ptr = arr;
        ptr += 10; // Incorrect pointer arithmetic, going out of bounds of the array
    }

    // Function with a signed integer overflow defect
    void signedIntegerOverflow() {
        int a = INT_MAX;
        int b = 1;
        int result = a + b; // Signed integer overflow
    }

    // Function with a signed integer underflow defect
    void signedIntegerUnderflow() {
        int a = INT_MIN;
        int b = 1;
        int result = a - b; // Signed integer underflow
    }

    // Function with a divide-by-zero defect in a loop
    void divideByZeroInLoop() {
        for (int i = 10; i >= -10; --i) {
            int result = 10 / i; // Division by zero for i = 0
            std::cout << "Result: " << result << std::endl;
        }
    }

    // Function with an unused variable defect
    void unusedVariable() {
        int unusedVar; // This variable is declared but not used
    }

    // Function with a floating-point divide-by-zero defect
    void floatingPointDivideByZero() {
        double a = 10.0;
        double b = 0.0;
        double result = a / b; // Floating-point division by zero
    }
}

#if 0
int main() {
    bufferOverflow();
    useAfterFree();
    memoryLeak();
    uninitializedVariable();
    divisionByZero();
    nullPointerDereference();
    mismatchedDelete();
    int* danglingPtr = danglingPointer(); // Avoid using danglingPtr
    int* stackAddressPtr = stackAddressEscape(); // Avoid using stackAddressPtr
    useOfStalePointer();
    writeToReadOnlyMemory();
    bufferOverflowInMemcpy();
    bufferOverflowInStrncpy();
    bufferOverflowInSprintf();
    bufferOverflowInSscanf();
    bufferOverflowInSnprintf();
    memoryLeakInLoop();
    useOfFreedPointer();
    bufferUnderflow();
    bufferUnderRead();
    useOfNullPointer();
    int missingReturn = missingReturnStatement(); // Avoid using missingReturn
    incorrectPointerArithmetic();
    signedIntegerOverflow();
    signedIntegerUnderflow();
    divideByZeroInLoop();
    unusedVariable();
    floatingPointDivideByZero();

    return 0;
}
#endif
