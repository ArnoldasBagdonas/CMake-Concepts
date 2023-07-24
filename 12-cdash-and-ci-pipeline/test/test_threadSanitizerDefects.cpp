// test_threadSanitizerDefects.cpp

// ThreadSanitizer (TSan) is a dynamic analysis tool that detects data race conditions in C++ programs,
// where multiple threads access shared data without proper synchronization.


#include "gtest/gtest.h"
#include "threadSanitizerDefects/threadSanitizerDefects.hpp"
using namespace threadSanitizer;
#include <iostream>
#include <future>
#include <chrono>


#define GTEST_TIMEOUT_BEGIN auto asyncFuture = std::async(std::launch::async, [this]()->void {
#define GTEST_TIMEOUT_END(X) return; }); \
EXPECT_TRUE(asyncFuture.wait_for(std::chrono::milliseconds(X)) != std::future_status::timeout);


// Function with a data race
TEST(ThreadSanitizerTest, AlwaysFail) {
    EXPECT_TRUE(false);
}

// Function with a data race
TEST(ThreadSanitizerTest, DataRace) {
    std::vector<std::thread> threads;

    // Creating multiple threads to test data races
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(dataRace);
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }
}

// Function with a deadlock
TEST(ThreadSanitizerTest, Deadlock) {
    //FIXME: how to test deadlock in gtest properly?
    // GTEST_TIMEOUT_BEGIN
    // deadlock();
    // GTEST_TIMEOUT_END(10000);

    // auto future = std::async(std::launch::async, []() {
    //     // Simulate some time-consuming task
    //     deadlock();
    // });
    // // Wait for the task to finish with a timeout of 3 seconds
    // // std::chrono::seconds timeoutDuration(3);
    // // std::future_status status = future.wait_for(timeoutDuration);

    // // Define the timeout duration
    // std::chrono::seconds timeoutDuration(3);

    // // Get the current time to calculate the timeout point
    // auto startTime = std::chrono::high_resolution_clock::now();
    // auto timeoutPoint = startTime + timeoutDuration;
    // std::future_status status = future.wait_for(std::chrono::seconds(0));
    // // Wait for the task to finish or timeout
    // while ((std::chrono::high_resolution_clock::now() < timeoutPoint) && ((std::future_status::ready != status))) {
    //     // Check if the task has completed
    //     status = future.wait_for(std::chrono::seconds(0));
    // }
    // EXPECT_EQ(std::future_status::ready, status);
    
}

// Function with a lock order inversion
TEST(ThreadSanitizerTest, LockOrderInversion) {
    lockOrderInversion();
}

// Function with a use of a non-joinable thread
TEST(ThreadSanitizerTest, NonJoinableThread) {
    nonJoinableThread();
}

// Function with a double locking of the same mutex
TEST(ThreadSanitizerTest, DoubleLocking) {
    //FIXME: how to test deadlock in gtest properly?
    //doubleLocking();
}

// Function with a missing unlock of a mutex
TEST(ThreadSanitizerTest, MissingUnlock) {
    missingUnlock();
}

// Function with a missing lock of a mutex
TEST(ThreadSanitizerTest, MissingLock) {
    missingLock();
}

// Function with a use of a stale reference
TEST(ThreadSanitizerTest, UseOfStaleReference) {
    useOfStaleReference();
}

// Function with a use of a stack-allocated variable in a thread
TEST(ThreadSanitizerTest, UseOfStackVariableInThread) {
    useOfStackVariableInThread();
}

// Function with a shared resource accessed without synchronization
TEST(ThreadSanitizerTest, SharedResourceAccess) {
    sharedResourceAccess();
}

// Function with a use of a non-atomic variable in atomic context
TEST(ThreadSanitizerTest, UseOfNonAtomicVariable) {
    useOfNonAtomicVariable();
}

// Function with a use of an atomic variable without synchronization
TEST(ThreadSanitizerTest, UseOfAtomicVariableWithoutSync) {
    useOfAtomicVariableWithoutSync();
}

// Function with a use of a shared object in a condition variable wait
TEST(ThreadSanitizerTest, ConditionVariableWait) {
    //FIXME: how to test deadlock in gtest properly?
    //conditionVariableWait();
}

// Function with a use of a released condition variable
TEST(ThreadSanitizerTest, UseOfReleasedConditionVariable) {
    useOfReleasedConditionVariable();
}

// Function with a use of a condition variable without locking
TEST(ThreadSanitizerTest, UseOfConditionVariableWithoutLocking) {
    useOfConditionVariableWithoutLocking();
}
