// threadSanitizerDefects.cpp

// ThreadSanitizer (TSan) is a dynamic analysis tool that detects data race conditions in C++ programs,
// where multiple threads access shared data without proper synchronization.

#include "threadSanitizerDefects/threadSanitizerDefects.hpp"

#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <atomic>
#include <condition_variable>

namespace threadSanitizer
{
    std::mutex mtx;

    // Function with a data race
    int sharedValue = 0;
    void dataRace() {
        for (int i = 0; i < 10000; ++i) {
            mtx.lock();
            sharedValue++; // Data race: Multiple threads accessing sharedValue without proper synchronization
            mtx.unlock();
        }
    }

    // Function with a deadlock
    void deadlock() {
        std::lock_guard<std::mutex> lock1(mtx);
        std::lock_guard<std::mutex> lock2(mtx); // Deadlock: Two threads attempt to lock the mutexes in different order
    }

    // Function with a lock order inversion
    std::mutex mtx1, mtx2;
    void lockOrderInversion() {
        std::lock_guard<std::mutex> lock1(mtx1);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        std::lock_guard<std::mutex> lock2(mtx2);
        // Lock order inversion: Thread 1 holds mtx1 and waits for mtx2, while Thread 2 holds mtx2 and waits for mtx1
    }

    // Function with a use of a non-joinable thread
    void nonJoinableThread() {
        std::thread t([]() { std::cout << "Non-joinable thread function." << std::endl; });
        // Non-joinable thread: The program exits without waiting for the thread to complete
    }

    // Function with a double locking of the same mutex
    void doubleLocking() {
        mtx.lock();
        mtx.lock(); // Double locking of the same mutex: Leads to undefined behavior and potential deadlock
        mtx.unlock();
    }

    // Function with a missing unlock of a mutex
    void missingUnlock() {
        mtx.lock();
        // Missing unlock: The mutex is not unlocked before returning from the function, causing potential deadlock
    }

    // Function with a missing lock of a mutex
    void missingLock() {
        // Missing lock: The function accesses shared data without acquiring the mutex, leading to data race
        sharedValue++;
    }

    // Function with a use of a stale reference
    int* danglingPtr;
    void useOfStaleReference() {
        int value = 42;
        danglingPtr = &value;
        // Stale reference: The function stores the address of a local variable and returns it, causing a dangling pointer
    }

    // Function with a use of a stack-allocated variable in a thread
    void useOfStackVariableInThread() {
        int stackVar = 100;
        std::thread t([&]() {
            std::cout << "StackVar from thread: " << stackVar << std::endl;
        });
        t.join();
        // Use of stackVar in a thread: The thread may access the variable after it goes out of scope, leading to undefined behavior
    }

    // Function with a shared resource accessed without synchronization
    int sharedResource = 0;
    void sharedResourceAccess() {
        if (sharedResource == 0) { // Accessing sharedResource without proper synchronization
            sharedResource = 1;
        }
    }

    // Function with a use of a non-atomic variable in atomic context
    void useOfNonAtomicVariable() {
        std::atomic<int> atomicVar;
        int nonAtomicVar = 10;
        atomicVar.store(nonAtomicVar); // Use of non-atomic variable in an atomic context
    }

    // Function with a use of an atomic variable without synchronization
    std::atomic<int> atomicValue;
    void useOfAtomicVariableWithoutSync() {
        atomicValue++; // Use of atomic variable without proper synchronization
    }

    // Function with a use of a shared object in a condition variable wait
    std::condition_variable cv;
    bool condition = false;
    void conditionVariableWait() {
        std::unique_lock<std::mutex> lock(mtx);
        while (!condition) {
            cv.wait(lock); // Use of shared object in a condition variable wait without proper synchronization
        }
    }

    // Function with a use of a released condition variable
    void useOfReleasedConditionVariable() {
        cv.notify_one();
        cv.notify_all();
        // Use of released condition variable: Not synchronized with the condition variable wait
    }

    // Function with a use of a condition variable without locking
    void useOfConditionVariableWithoutLocking() {
        condition = true;
        cv.notify_all();
        // Use of condition variable without locking: May lead to undefined behavior and potential data race
    }
}

#if 0
int main() {
    std::vector<std::thread> threads;

    // Creating multiple threads to test data races
    for (int i = 0; i < 10; ++i) {
        threads.emplace_back(dataRace);
    }

    // Wait for all threads to finish
    for (auto& t : threads) {
        t.join();
    }

    deadlock();
    lockOrderInversion();
    nonJoinableThread();
    doubleLocking();
    missingUnlock();
    missingLock();
    useOfStaleReference();
    useOfStackVariableInThread();
    sharedResourceAccess();
    useOfNonAtomicVariable();
    useOfAtomicVariableWithoutSync();
    conditionVariableWait();
    useOfReleasedConditionVariable();
    useOfConditionVariableWithoutLocking();

    return 0;
}
#endif
