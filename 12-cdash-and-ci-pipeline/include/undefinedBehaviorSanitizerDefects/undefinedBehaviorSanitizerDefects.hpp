// undefinedBehaviorSanitizerDefects.hpp

// UndefinedBehaviorSanitizer (UBSan) is a powerful tool that can detect various undefined
// behavior in C++ code, such as signed integer overflow, division by zero, null pointer dereference, and more.

#pragma once

#include <iostream>
#include <cstring>
#include <vector>

namespace undefinedBehaviorSanitizer
{
    // Function with signed integer overflow
    void signedIntegerOverflow();

    // Function with signed integer underflow
    void signedIntegerUnderflow();

    // Function with division by zero
    void divisionByZero();

    // Function with null pointer dereference
    void nullPointerDereference();

    // Function with undefined shift left operation
    void undefinedShiftLeft();

    // Function with undefined shift right operation
    void undefinedShiftRight();

    // Function with undefined behavior due to floating-point arithmetic
    void floatingPointArithmetic();

    // Function with undefined behavior due to uninitialized variable
    void uninitializedVariable();

    // Function with undefined behavior due to out-of-bounds access
    void outOfBoundsAccess();

    // Function with undefined behavior due to null pointer comparison
    void nullPointerComparison();

    // Function with undefined behavior due to accessing a dangling pointer
    int* danglingPointer();

    // Function with undefined behavior due to using a stale pointer
    void useStalePointer();

    // Function with undefined behavior due to pointer arithmetic out of bounds
    void pointerArithmeticOutOfBounds();

    // Function with undefined behavior due to reading from a freed pointer
    void readFromFreedPointer();

    // Function with undefined behavior due to writing to a freed pointer
    void writeToFreedPointer();

    // Function with undefined behavior due to using an uninitialized pointer
    void useUninitializedPointer();

    // Function with undefined behavior due to accessing a null reference
    void accessNullReference();

    // Function with undefined behavior due to dereferencing a null reference
    void dereferenceNullReference();

    // Function with undefined behavior due to calling a function with the wrong number of arguments
    void callFunctionWithWrongArguments();

    // Function with undefined behavior due to accessing an array with a negative index
    void accessArrayWithNegativeIndex();

    // Function with undefined behavior due to accessing a variable outside its lifetime
    void accessVariableOutsideLifetime();

    // Function with undefined behavior due to signed integer overflow in multiplication
    void signedIntegerOverflowInMultiplication();

    // Function with undefined behavior due to integer division with truncation
    void integerDivisionWithTruncation();

    // Function with undefined behavior due to dereferencing a pointer to non-object type
    void dereferencePointerToNonObject();

    // Function with undefined behavior due to using an invalid pointer value
    void useInvalidPointerValue();

    // Function with undefined behavior due to reading from a null pointer
    void readFromNullPointer();

    // Function with undefined behavior due to writing to a null pointer
    void writeToNullPointer();

    // Function with undefined behavior due to pointer arithmetic with an invalid pointer
    void pointerArithmeticWithInvalidPointer();

    // Function with undefined behavior due to calling a function through a function pointer with a mismatched signature
    void callFunctionThroughMismatchedFunctionPointer();

    // Function with undefined behavior due to an invalid use of reinterpret_cast
    void invalidReinterpretCast();

    // Function with undefined behavior due to calling a deleted function
    void callDeletedFunction();

    // Function with undefined behavior due to creating a reference to a temporary object
    void referenceToTemporaryObject();
}
