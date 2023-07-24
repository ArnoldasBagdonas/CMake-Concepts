// addressSanitizerDefects.hpp

// AddressSanitizer (ASan) is a powerful tool that can detect various memory-related
// defects in C++ code, such as buffer overflows, use-after-free, and memory leaks.

#pragma once

namespace addressSanitizer
{

    // Function with a buffer overflow defect
    void bufferOverflow();

    // Function with a use-after-free defect
    void useAfterFree();

    // Function with a memory leak defect
    void memoryLeak();

    // Function with uninitialized variable defect
    void uninitializedVariable();

    // Function with uninitialized memory reads
    void uninitializedMemoryReads();

    // Function with division by zero defect
    void divisionByZero();

    // Function with null pointer dereference defect
    void nullPointerDereference();

    // Function with mismatched delete defect
    void mismatchedDelete();

    // Function with a dangling pointer defect
    int* danglingPointer();

    // Function with a stack address escape defect
    int* stackAddressEscape();

    // Function with a use of a stale pointer defect
    void useOfStalePointer();

    // Function with a write to read-only memory defect
    void writeToReadOnlyMemory();

    // Function with a buffer overflow in memcpy defect
    void bufferOverflowInMemcpy();

    // Function with a buffer overflow in strncpy defect
    void bufferOverflowInStrncpy();

    // Function with a buffer overflow in sprintf defect
    void bufferOverflowInSprintf();

    // Function with a buffer overflow in sscanf defect
    void bufferOverflowInSscanf();

    // Function with a buffer overflow in snprintf defect
    void bufferOverflowInSnprintf();

    // Function with a memory leak in a loop defect
    void memoryLeakInLoop();

    // Function with a use of a freed pointer defect
    void useOfFreedPointer();

    // Function with a buffer underflow defect
    void bufferUnderflow();

    // Function with a buffer under-read defect
    void bufferUnderRead();

    // Function with a use of a null pointer defect
    void useOfNullPointer();

    // Function with a missing return statement defect
    int missingReturnStatement();

    // Function with an incorrect pointer arithmetic defect
    void incorrectPointerArithmetic();

    // Function with a signed integer overflow defect
    void signedIntegerOverflow();

    // Function with a signed integer underflow defect
    void signedIntegerUnderflow();

    // Function with a divide-by-zero defect in a loop
    void divideByZeroInLoop();

    // Function with an unused variable defect
    void unusedVariable();

    // Function with a floating-point divide-by-zero defect
    void floatingPointDivideByZero();

}
