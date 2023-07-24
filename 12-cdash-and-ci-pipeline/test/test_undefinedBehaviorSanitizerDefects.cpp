// test_undefinedBehaviorSanitizerDefects.cpp

// UndefinedBehaviorSanitizer (UBSan) is a powerful tool that can detect various undefined
// behavior in C++ code, such as signed integer overflow, division by zero, null pointer dereference, and more.

#include "gtest/gtest.h"

#include "undefinedBehaviorSanitizerDefects/undefinedBehaviorSanitizerDefects.hpp"
using namespace undefinedBehaviorSanitizer;

// Function with signed integer overflow
TEST(UndefinedBehaviorSanitizerTest, SignedIntegerOverflow) {
    signedIntegerOverflow();
}

// Function with signed integer underflow
TEST(UndefinedBehaviorSanitizerTest, SignedIntegerUnderflow) {
    signedIntegerUnderflow();
}

// Function with division by zero
TEST(UndefinedBehaviorSanitizerTest, DivisionByZero) {
    divisionByZero();
}

// Function with null pointer dereference
TEST(UndefinedBehaviorSanitizerTest, NullPointerDereference) {
    nullPointerDereference();
}

// Function with undefined shift left operation
TEST(UndefinedBehaviorSanitizerTest, UndefinedShiftLef) {
    undefinedShiftLeft();
}

// Function with undefined shift right operation
TEST(UndefinedBehaviorSanitizerTest, UndefinedShiftRight) {
    undefinedShiftRight();
}

// Function with undefined behavior due to floating-point arithmetic
TEST(UndefinedBehaviorSanitizerTest, FloatingPointArithmetic) {
    floatingPointArithmetic();
}

// Function with undefined behavior due to uninitialized variable
TEST(UndefinedBehaviorSanitizerTest, UninitializedVariable) {
    uninitializedVariable();
}

// Function with undefined behavior due to null pointer comparison
TEST(UndefinedBehaviorSanitizerTest, NullPointerComparison) {
    nullPointerComparison();
}

// Function with undefined behavior due to using a stale pointer
TEST(UndefinedBehaviorSanitizerTest, UseStalePointer) {
    useStalePointer();
}

// Function with undefined behavior due to pointer arithmetic out of bounds
TEST(UndefinedBehaviorSanitizerTest, PointerArithmeticOutOfBounds) {
    pointerArithmeticOutOfBounds();
}

// Function with undefined behavior due to reading from a freed pointer
TEST(UndefinedBehaviorSanitizerTest, ReadFromFreedPointer) {
    readFromFreedPointer();
}

// Function with undefined behavior due to writing to a freed pointer
TEST(UndefinedBehaviorSanitizerTest, WriteToFreedPointer) {
    writeToFreedPointer();
}

// Function with undefined behavior due to using an uninitialized pointer
TEST(UndefinedBehaviorSanitizerTest, UseUninitializedPointer) {
    useUninitializedPointer();
}

// Function with undefined behavior due to accessing a null reference
TEST(UndefinedBehaviorSanitizerTest, AccessNullReference) {
    accessNullReference();
}

// Function with undefined behavior due to dereferencing a null reference
TEST(UndefinedBehaviorSanitizerTest, DereferenceNullReference) {
    dereferenceNullReference();
}

// Function with undefined behavior due to calling a function with the wrong number of arguments
TEST(UndefinedBehaviorSanitizerTest, CallFunctionWithWrongArguments) {
    callFunctionWithWrongArguments();
}

// Function with undefined behavior due to accessing an array with a negative index
TEST(UndefinedBehaviorSanitizerTest, AccessArrayWithNegativeIndex) {
    accessArrayWithNegativeIndex();
}

// Function with undefined behavior due to accessing a variable outside its lifetime
TEST(UndefinedBehaviorSanitizerTest, AccessVariableOutsideLifetime) {
    accessVariableOutsideLifetime();
}

// Function with undefined behavior due to signed integer overflow in multiplication
TEST(UndefinedBehaviorSanitizerTest, SignedIntegerOverflowInMultiplication) {
    signedIntegerOverflowInMultiplication();
}

// Function with undefined behavior due to integer division with truncation
TEST(UndefinedBehaviorSanitizerTest, IntegerDivisionWithTruncation) {
    integerDivisionWithTruncation();
}

// Function with undefined behavior due to dereferencing a pointer to non-object type
TEST(UndefinedBehaviorSanitizerTest, DereferencePointerToNonObject) {
    dereferencePointerToNonObject();
}

// Function with undefined behavior due to using an invalid pointer value
TEST(UndefinedBehaviorSanitizerTest, UseInvalidPointerValue) {
    useInvalidPointerValue();
}

// Function with undefined behavior due to reading from a null pointer
TEST(UndefinedBehaviorSanitizerTest, ReadFromNullPointer) {
    readFromNullPointer();
}

// Function with undefined behavior due to writing to a null pointer
TEST(UndefinedBehaviorSanitizerTest, WriteToNullPointer) {
    writeToNullPointer();
}

// Function with undefined behavior due to pointer arithmetic with an invalid pointer
TEST(UndefinedBehaviorSanitizerTest, PointerArithmeticWithInvalidPointer) {
    pointerArithmeticWithInvalidPointer();
}

// Function with undefined behavior due to calling a function through a function pointer with a mismatched signature
TEST(UndefinedBehaviorSanitizerTest, CallFunctionThroughMismatchedFunctionPointer) {
    callFunctionThroughMismatchedFunctionPointer();
}

// Function with undefined behavior due to an invalid use of reinterpret_cast
TEST(UndefinedBehaviorSanitizerTest, InvalidReinterpretCast) {
    invalidReinterpretCast();
}

// Function with undefined behavior due to calling a deleted function
TEST(UndefinedBehaviorSanitizerTest, CallDeletedFunction) {
    callDeletedFunction();
}

// Function with undefined behavior due to creating a reference to a temporary object
TEST(UndefinedBehaviorSanitizerTest, ReferenceToTemporaryObject) {
    referenceToTemporaryObject();
}
