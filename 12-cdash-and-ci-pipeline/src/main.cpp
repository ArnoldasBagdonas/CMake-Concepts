
#include <iostream>

#include "addressSanitizerDefects/addressSanitizerDefects.hpp"
#include "threadSanitizerDefects/threadSanitizerDefects.hpp"
#include "undefinedBehaviorSanitizerDefects/undefinedBehaviorSanitizerDefects.hpp"

int main() {

    // AddressSanitizer (ASan) is a dynamic analysis tool  that can detect various memory-related defects
    // in C++ code, such as buffer overflows, use-after-free, and memory leaks.

    addressSanitizer::bufferOverflow();
    addressSanitizer::useAfterFree();
    addressSanitizer::memoryLeak();
    addressSanitizer::uninitializedVariable();
    addressSanitizer::uninitializedMemoryReads();
    addressSanitizer::divisionByZero();
    addressSanitizer::nullPointerDereference();
    addressSanitizer::mismatchedDelete();
    int* danglingPtr = addressSanitizer::danglingPointer(); // Avoid using danglingPtr
    int* stackAddressPtr = addressSanitizer::stackAddressEscape(); // Avoid using stackAddressPtr
    addressSanitizer::useOfStalePointer();
    addressSanitizer::writeToReadOnlyMemory();
    addressSanitizer::bufferOverflowInMemcpy();
    addressSanitizer::bufferOverflowInStrncpy();
    addressSanitizer::bufferOverflowInSprintf();
    addressSanitizer::bufferOverflowInSscanf();
    addressSanitizer::bufferOverflowInSnprintf();
    addressSanitizer::memoryLeakInLoop();
    addressSanitizer::useOfFreedPointer();
    addressSanitizer::bufferUnderflow();
    addressSanitizer::bufferUnderRead();
    addressSanitizer::useOfNullPointer();
    int missingReturn = addressSanitizer::missingReturnStatement(); // Avoid using missingReturn
    addressSanitizer::incorrectPointerArithmetic();
    addressSanitizer::signedIntegerOverflow();
    addressSanitizer::signedIntegerUnderflow();
    addressSanitizer::divideByZeroInLoop();
    addressSanitizer::unusedVariable();
    addressSanitizer::floatingPointDivideByZero();

    // ThreadSanitizer (TSan) is a dynamic analysis tool that detects data race conditions in C++ programs,
    // where multiple threads access shared data without proper synchronization.

    std::vector<std::thread> threads;

    // Creating multiple threads to test data races
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(threadSanitizer::dataRace);
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    threadSanitizer::deadlock();
    threadSanitizer::lockOrderInversion();
    threadSanitizer::nonJoinableThread();
    threadSanitizer::doubleLocking();
    threadSanitizer::missingUnlock();
    threadSanitizer::missingLock();
    threadSanitizer::useOfStaleReference();
    threadSanitizer::useOfStackVariableInThread();
    threadSanitizer::sharedResourceAccess();
    threadSanitizer::useOfNonAtomicVariable();
    threadSanitizer::useOfAtomicVariableWithoutSync();
    threadSanitizer::conditionVariableWait();
    threadSanitizer::useOfReleasedConditionVariable();
    threadSanitizer::useOfConditionVariableWithoutLocking();

    // UndefinedBehaviorSanitizer (UBSan) is a powerful tool that can detect various undefined
    // behavior in C++ code, such as signed integer overflow, division by zero, null pointer dereference, and more.

    undefinedBehaviorSanitizer::signedIntegerOverflow();
    undefinedBehaviorSanitizer::signedIntegerUnderflow();
    undefinedBehaviorSanitizer::divisionByZero();
    undefinedBehaviorSanitizer::nullPointerDereference();
    undefinedBehaviorSanitizer::undefinedShiftLeft();
    undefinedBehaviorSanitizer::undefinedShiftRight();
    undefinedBehaviorSanitizer::floatingPointArithmetic();
    undefinedBehaviorSanitizer::uninitializedVariable();
    undefinedBehaviorSanitizer::outOfBoundsAccess();
    undefinedBehaviorSanitizer::nullPointerComparison();
    undefinedBehaviorSanitizer::useStalePointer();
    undefinedBehaviorSanitizer::pointerArithmeticOutOfBounds();
    undefinedBehaviorSanitizer::readFromFreedPointer();
    undefinedBehaviorSanitizer::writeToFreedPointer();
    undefinedBehaviorSanitizer::useUninitializedPointer();
    undefinedBehaviorSanitizer::accessNullReference();
    undefinedBehaviorSanitizer::dereferenceNullReference();
    undefinedBehaviorSanitizer::callFunctionWithWrongArguments();
    undefinedBehaviorSanitizer::accessArrayWithNegativeIndex();
    undefinedBehaviorSanitizer::accessVariableOutsideLifetime();
    undefinedBehaviorSanitizer::signedIntegerOverflowInMultiplication();
    undefinedBehaviorSanitizer::integerDivisionWithTruncation();
    undefinedBehaviorSanitizer::dereferencePointerToNonObject();
    undefinedBehaviorSanitizer::useInvalidPointerValue();
    undefinedBehaviorSanitizer::readFromNullPointer();
    undefinedBehaviorSanitizer::writeToNullPointer();
    undefinedBehaviorSanitizer::pointerArithmeticWithInvalidPointer();
    undefinedBehaviorSanitizer::callFunctionThroughMismatchedFunctionPointer();
    undefinedBehaviorSanitizer::invalidReinterpretCast();
    undefinedBehaviorSanitizer::callDeletedFunction();
    undefinedBehaviorSanitizer::referenceToTemporaryObject();
    
    return 0;
}