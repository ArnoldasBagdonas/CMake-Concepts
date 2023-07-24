// undefinedBehaviorSanitizerDefects.cpp

// UndefinedBehaviorSanitizer (UBSan) is a powerful tool that can detect various undefined
// behavior in C++ code, such as signed integer overflow, division by zero, null pointer dereference, and more.

#include "undefinedBehaviorSanitizerDefects/undefinedBehaviorSanitizerDefects.hpp"

#include <iostream>
#include <cstring>
#include <vector>
#include <limits.h>

namespace undefinedBehaviorSanitizer
{
    // Function with signed integer overflow
    void signedIntegerOverflow() {
        int x = INT_MAX;
        int result = x + 1; // Signed integer overflow
        std::cout << "Signed Integer Overflow: " << result << std::endl;
    }

    // Function with signed integer underflow
    void signedIntegerUnderflow() {
        int x = INT_MIN;
        int result = x - 1; // Signed integer underflow
        std::cout << "Signed Integer Underflow: " << result << std::endl;
    }

    // Function with division by zero
    void divisionByZero() {
        int x = 10;
        int y = 0;
        int result = x / y; // Division by zero
        std::cout << "Division by Zero: " << result << std::endl;
    }

    // Function with null pointer dereference
    void nullPointerDereference() {
        int* ptr = nullptr;
        *ptr = 5; // Null pointer dereference
    }

    // Function with undefined shift left operation
    void undefinedShiftLeft() {
        int x = 1;
        int result = x << 32; // Shift left with too large shift count (undefined behavior)
        std::cout << "Undefined Shift Left: " << result << std::endl;
    }

    // Function with undefined shift right operation
    void undefinedShiftRight() {
        int x = -1;
        int result = x >> 32; // Shift right with too large shift count (undefined behavior)
        std::cout << "Undefined Shift Right: " << result << std::endl;
    }

    // Function with undefined behavior due to floating-point arithmetic
    void floatingPointArithmetic() {
        float x = 0.0;
        float y = 0.0;
        float result = x / y; // Floating-point division by zero (undefined behavior)
        std::cout << "Floating-point Arithmetic: " << result << std::endl;
    }

    // Function with undefined behavior due to uninitialized variable
    void uninitializedVariable() {
        int x;
        if (x > 0) { // Using uninitialized variable
            std::cout << "Uninitialized Variable: " << x << std::endl;
        }
    }

    // Function with undefined behavior due to out-of-bounds access
    void outOfBoundsAccess() {
        int arr[5] = {1, 2, 3, 4, 5};
        int index = 5;
        int value = arr[index]; // Out-of-bounds access
        std::cout << "Out-of-Bounds Access: " << value << std::endl;
    }

    // Function with undefined behavior due to null pointer comparison
    void nullPointerComparison() {
        int* ptr = nullptr;
        if (ptr == nullptr) { // Null pointer comparison
            std::cout << "Null Pointer Comparison" << std::endl;
        }
    }

    // Function with undefined behavior due to accessing a dangling pointer
    int* danglingPointer() {
        int value = 10;
        return &value; // Returning a pointer to a local variable (dangling pointer)
    }

    // Function with undefined behavior due to using a stale pointer
    void useStalePointer() {
        int* ptr = danglingPointer();
        *ptr = 42; // Using a stale pointer
        std::cout << "Use of Stale Pointer: " << *ptr << std::endl;
    }

    // Function with undefined behavior due to pointer arithmetic out of bounds
    void pointerArithmeticOutOfBounds() {
        int arr[5] = {1, 2, 3, 4, 5};
        int* ptr = arr;
        ptr += 10; // Pointer arithmetic out of bounds
        std::cout << "Pointer Arithmetic Out of Bounds: " << *ptr << std::endl;
    }

    // Function with undefined behavior due to reading from a freed pointer
    void readFromFreedPointer() {
        int* ptr = new int;
        delete ptr;
        int value = *ptr; // Reading from a freed pointer
        std::cout << "Read From Freed Pointer: " << value << std::endl;
    }

    // Function with undefined behavior due to writing to a freed pointer
    void writeToFreedPointer() {
        int* ptr = new int;
        delete ptr;
        *ptr = 10; // Writing to a freed pointer
        std::cout << "Write To Freed Pointer: " << *ptr << std::endl;
    }

    // Function with undefined behavior due to using an uninitialized pointer
    void useUninitializedPointer() {
        int* ptr;
        *ptr = 5; // Using an uninitialized pointer
        std::cout << "Use of Uninitialized Pointer: " << *ptr << std::endl;
    }

    // Function with undefined behavior due to accessing a null reference
    void accessNullReference() {
        int* ptr = nullptr;
        int& ref = *ptr; // Accessing a null reference
        std::cout << "Access Null Reference: " << ref << std::endl;
    }

    // Function with undefined behavior due to dereferencing a null reference
    void dereferenceNullReference() {
        int* ptr = nullptr;
        *ptr = 42; // Dereferencing a null reference
        std::cout << "Dereference Null Reference: " << *ptr << std::endl;
    }

    // Function with undefined behavior due to calling a function with the wrong number of arguments
    void callFunctionWithWrongArguments() {
        int result = printf("%d %d", 1, 2, 3); // Calling printf with the wrong number of arguments
        std::cout << "Call Function With Wrong Arguments: " << result << std::endl;
    }

    // Function with undefined behavior due to accessing an array with a negative index
    void accessArrayWithNegativeIndex() {
        int arr[5] = {1, 2, 3, 4, 5};
        int value = arr[-1]; // Accessing array with a negative index
        std::cout << "Access Array With Negative Index: " << value << std::endl;
    }

    // Function with undefined behavior due to accessing a variable outside its lifetime
    void accessVariableOutsideLifetime() {
        int* ptr;
        {
            int value = 42;
            ptr = &value;
        }
        int result = *ptr; // Accessing a variable outside its lifetime
        std::cout << "Access Variable Outside Lifetime: " << result << std::endl;
    }

    // Function with undefined behavior due to signed integer overflow in multiplication
    void signedIntegerOverflowInMultiplication() {
        int x = INT_MAX;
        int result = x * 2; // Signed integer overflow in multiplication
        std::cout << "Signed Integer Overflow in Multiplication: " << result << std::endl;
    }

    // Function with undefined behavior due to integer division with truncation
    void integerDivisionWithTruncation() {
        int x = 5;
        int y = 2;
        int result = x / y; // Integer division with truncation
        std::cout << "Integer Division with Truncation: " << result << std::endl;
    }

    // Function with undefined behavior due to dereferencing a pointer to non-object type
    void dereferencePointerToNonObject() {
        int* ptr = (int*)1;
        int value = *ptr; // Dereferencing a pointer to non-object type
        std::cout << "Dereference Pointer to Non-Object: " << value << std::endl;
    }

    // Function with undefined behavior due to using an invalid pointer value
    void useInvalidPointerValue() {
        int* ptr = (int*)1000;
        int value = *ptr; // Using an invalid pointer value
        std::cout << "Use Invalid Pointer Value: " << value << std::endl;
    }

    // Function with undefined behavior due to reading from a null pointer
    void readFromNullPointer() {
        int* ptr = nullptr;
        int value = *ptr; // Reading from a null pointer
        std::cout << "Read From Null Pointer: " << value << std::endl;
    }

    // Function with undefined behavior due to writing to a null pointer
    void writeToNullPointer() {
        int* ptr = nullptr;
        *ptr = 10; // Writing to a null pointer
        std::cout << "Write To Null Pointer: " << *ptr << std::endl;
    }

    // Function with undefined behavior due to pointer arithmetic with an invalid pointer
    void pointerArithmeticWithInvalidPointer() {
        int* ptr = nullptr;
        ptr++; // Pointer arithmetic with an invalid pointer
        std::cout << "Pointer Arithmetic with Invalid Pointer" << std::endl;
    }

    // Function with undefined behavior due to calling a function through a function pointer with a mismatched signature
    void func(float x)
    {
        std::cout << "Function Pointer: " << x << std::endl;
    }
    void callFunctionThroughMismatchedFunctionPointer() {
        typedef void (*FuncType)(int);
        FuncType funcPtr = (FuncType)&func;
        funcPtr(5); // Calling function through function pointer with a mismatched signature
    }

    // Function with undefined behavior due to an invalid use of reinterpret_cast
    void invalidReinterpretCast() {
        int x = 42;
        float* ptr = reinterpret_cast<float*>(&x); // Invalid reinterpret_cast
        std::cout << "Invalid Reinterpret Cast: " << *ptr << std::endl;
    }

    // Function with undefined behavior due to calling a deleted function
    struct DeletedFunction {
        DeletedFunction() = delete;
        void operator()() {}
    };
    void callDeletedFunction() {
        // FIXME: fix compiler error message
        // DeletedFunction df;
        // df(); // Calling a deleted function
    }

    // Function with undefined behavior due to creating a reference to a temporary object
    const int& returnTempObject() {
        return 42;
    }
    void referenceToTemporaryObject() {
        const int& ref = returnTempObject(); // Creating a reference to a temporary object
        std::cout << "Reference to Temporary Object: " << ref << std::endl;
    }
}

#if 0
int main() {
    signedIntegerOverflow();
    signedIntegerUnderflow();
    divisionByZero();
    nullPointerDereference();
    undefinedShiftLeft();
    undefinedShiftRight();
    floatingPointArithmetic();
    uninitializedVariable();
    outOfBoundsAccess();
    nullPointerComparison();
    useStalePointer();
    pointerArithmeticOutOfBounds();
    readFromFreedPointer();
    writeToFreedPointer();
    useUninitializedPointer();
    accessNullReference();
    dereferenceNullReference();
    callFunctionWithWrongArguments();
    accessArrayWithNegativeIndex();
    accessVariableOutsideLifetime();
    signedIntegerOverflowInMultiplication();
    integerDivisionWithTruncation();
    dereferencePointerToNonObject();
    useInvalidPointerValue();
    readFromNullPointer();
    writeToNullPointer();
    pointerArithmeticWithInvalidPointer();
    callFunctionThroughMismatchedFunctionPointer();
    invalidReinterpretCast();
    callDeletedFunction();
    referenceToTemporaryObject();

    return 0;
}
#endif