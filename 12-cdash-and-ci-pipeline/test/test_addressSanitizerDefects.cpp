// test_addressSanitizerDefects.cpp

// AddressSanitizer (ASan) is a dynamic analysis tool  that can detect various memory-related defects
// in C++ code, such as buffer overflows, use-after-free, and memory leaks.

#include "gtest/gtest.h"

#include "addressSanitizerDefects/addressSanitizerDefects.hpp"
using namespace addressSanitizer;

// Function with a buffer overflow defect
TEST(AddressSanitizerTest, BufferOverflow) {
    bufferOverflow();
}

// Function with a use-after-free defect
TEST(AddressSanitizerTest, UseAfterFree) {
    useAfterFree();
}

// Function with a memory leak defect
TEST(AddressSanitizerTest, MemoryLeak) {
    memoryLeak();
}

// Function with uninitialized variable defect
TEST(AddressSanitizerTest, UninitializedVariable) {
    uninitializedVariable();
}

// Function with uninitialized memory reads
TEST(AddressSanitizerTest, UninitializedMemoryReads) {
    uninitializedMemoryReads();
}

// Function with division by zero defect
TEST(AddressSanitizerTest, DivisionByZero) {
    divisionByZero();
}

// Function with null pointer dereference defect
TEST(AddressSanitizerTest, NullPointerDereference) {
    nullPointerDereference();
}

// Function with mismatched delete defect
TEST(AddressSanitizerTest, MismatchedDelete) {
    mismatchedDelete();
}

// Function with a dangling pointer defect
TEST(AddressSanitizerTest, DanglingPointer) {
    int* danglingPtr = danglingPointer(); // Avoid using danglingPtr
}

// Function with a stack address escape defect
TEST(AddressSanitizerTest, StackAddressEscape) {
    int* stackAddressPtr = stackAddressEscape(); // Avoid using stackAddressPtr
}

// Function with a use of a stale pointer defect
TEST(AddressSanitizerTest, UseOfStalePointer) {
    useOfStalePointer();
}

// Function with a write to read-only memory defect
TEST(AddressSanitizerTest, WriteToReadOnlyMemory) {
    writeToReadOnlyMemory();
}

// Function with a buffer overflow in memcpy defect
TEST(AddressSanitizerTest, BufferOverflowInMemcpy) {
    bufferOverflowInMemcpy();
}

// Function with a buffer overflow in strncpy defect
TEST(AddressSanitizerTest, BufferOverflowInStrncpy) {
    bufferOverflowInStrncpy();
}

// Function with a buffer overflow in sprintf defect
TEST(AddressSanitizerTest, BufferOverflowInSprintf) {
    bufferOverflowInSprintf();
}

// Function with a buffer overflow in sscanf defect
TEST(AddressSanitizerTest, BufferOverflowInSscanf) {
    bufferOverflowInSscanf();
}

// Function with a buffer overflow in snprintf defect
TEST(AddressSanitizerTest, BufferOverflowInSnprintf) {
    bufferOverflowInSnprintf();
}

// Function with a memory leak in a loop defect
TEST(AddressSanitizerTest, MemoryLeakInLoop) {
    memoryLeakInLoop();
}

// Function with a use of a freed pointer defect
TEST(AddressSanitizerTest, UseOfFreedPointer) {
    useOfFreedPointer();
}

// Function with a buffer underflow defect
TEST(AddressSanitizerTest, BufferUnderflow) {
    bufferUnderflow();
}

// Function with a buffer under-read defect
TEST(AddressSanitizerTest, BufferUnderRead) {
    bufferUnderRead();
}

// Function with a use of a null pointer defect
TEST(AddressSanitizerTest, UseOfNullPointer) {
    useOfNullPointer();
}

// Function with a missing return statement defect
TEST(AddressSanitizerTest, MissingReturnStatement) {
    missingReturnStatement();
}

// Function with an incorrect pointer arithmetic defect
TEST(AddressSanitizerTest, IncorrectPointerArithmetic) {
    incorrectPointerArithmetic();
}

// Function with a signed integer overflow defect
TEST(AddressSanitizerTest, SignedIntegerOverflow) {
    signedIntegerOverflow();
}

// Function with a signed integer underflow defect
TEST(AddressSanitizerTest, SignedIntegerUnderflow) {
    signedIntegerUnderflow();
}

// Function with a divide-by-zero defect in a loop
TEST(AddressSanitizerTest, DivideByZeroInLoop) {
    divideByZeroInLoop();
}

// Function with an unused variable defect
TEST(AddressSanitizerTest, UnusedVariable) {
    unusedVariable();
}

// Function with a floating-point divide-by-zero defect
TEST(AddressSanitizerTest, FloatingPointDivideByZero) {
    floatingPointDivideByZero();
}
