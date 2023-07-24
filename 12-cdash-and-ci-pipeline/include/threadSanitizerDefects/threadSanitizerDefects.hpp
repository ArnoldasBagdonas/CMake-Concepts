// threadSanitizerDefects.hpp

// ThreadSanitizer (TSan) is a dynamic analysis tool that detects data race conditions in C++ programs,
// where multiple threads access shared data without proper synchronization. Below, I'll demonstrate
// a comprehensive C++ file with various defect examples, and then show how to add these failing
//  functions into Google Test (gtest) for testing using ThreadSanitizer.

#pragma once

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

namespace threadSanitizer
{
    // Function with a data race
    void dataRace();

    // Function with a deadlock
    void deadlock();

    // Function with a lock order inversion
    void lockOrderInversion();

    // Function with a use of a non-joinable thread
    void nonJoinableThread();

    // Function with a double locking of the same mutex
    void doubleLocking();

    // Function with a missing unlock of a mutex
    void missingUnlock();

    // Function with a missing lock of a mutex
    void missingLock();

    // Function with a use of a stale reference
    void useOfStaleReference();

    // Function with a use of a stack-allocated variable in a thread
    void useOfStackVariableInThread();

    // Function with a shared resource accessed without synchronization
    void sharedResourceAccess();

    // Function with a use of a non-atomic variable in atomic context
    void useOfNonAtomicVariable();

    // Function with a use of an atomic variable without synchronization
    void useOfAtomicVariableWithoutSync();

    // Function with a use of a shared object in a condition variable wait
    void conditionVariableWait();

    // Function with a use of a released condition variable
    void useOfReleasedConditionVariable();

    // Function with a use of a condition variable without locking
    void useOfConditionVariableWithoutLocking();
}
