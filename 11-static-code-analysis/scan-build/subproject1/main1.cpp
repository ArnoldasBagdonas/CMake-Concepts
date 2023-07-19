#include <stdio.h>
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
#include <mutex>

// 1. Null pointer dereference
void nullPointerDereference() {
    int* ptr = nullptr;
    *ptr = 42; // Null pointer dereference (High severity)
}

// 2. Division by zero
int divideByZero(int x) {
    return 100 / x; // Division by zero (High severity)
}

// 3. Memory leak
void memoryLeak() {
    int* arr = new int[5];
    // Missing delete[] arr;
}

// 4. Double free
void doubleFree() {
    int* arr = new int[5];
    delete[] arr;
    delete[] arr;
}

// 5. Out-of-bounds array access
void outOfBoundsAccess() {
    int arr[5] = {1, 2, 3, 4, 5};
    for (int i = 0; i <= 5; ++i) {
        std::cout << arr[i] << " "; // Out-of-bounds array access (High severity)
    }
}

// 6. Uninitialized variable
void uninitializedVariable() {
    int x;
    std::cout << x << std::endl; // Uninitialized variable (High severity)
}

// 7. Use-after-free
void useAfterFree() {
    int* ptr = new int(10);
    delete ptr;
    std::cout << *ptr << std::endl; // Use-after-free (High severity)
}

// 8. Incorrect format string
void incorrectFormatString() {
    int num = 42;
    printf("The answer is %s\n", num); // Incorrect format string
}

// 9. Integer overflow
void integerOverflow() {
    int maxInt = 2147483647;
    int overflowed = maxInt + 1;
    std::cout << "Overflowed value: " << overflowed << std::endl; // Integer overflow (High severity)
}

// 10. Resource leak - file not closed
void fileNotClosed() {
    FILE* file = fopen("data.txt", "r");
    // File operations
}

// 11. Floating-point comparison
bool compareFloats(float a, float b) {
    return a == b; // Floating-point comparison (High severity)
}

// 12. Unreachable code
void unreachableCode(int x) {
    if (x > 10) {
        return;
        std::cout << "This line is unreachable." << std::endl; // Unreachable code (High severity)
    }
}

// 13. Unused function parameter
void unusedParameter(int x, int /*unused*/) {
    std::cout << "Used parameter: " << x << std::endl; // Unused function parameter (High severity)
}

// 14. Infinite loop
void infiniteLoop() {
    while (true) {
        // Some logic
    }
}

// 15. Missing break in switch statement
void missingBreakInSwitch(int x) {
    switch (x) {
        case 1:
            std::cout << "x is 1" << std::endl;
            break;
        case 2:
            std::cout << "x is 2" << std::endl;
            break;
        // Missing break for other cases (High severity)
    }
}

// ... 15 more bugs, making a total of 30 bugs ...

int main() {
    nullPointerDereference();
    divideByZero(0);
    memoryLeak();
    doubleFree();
    outOfBoundsAccess();
    uninitializedVariable();
    useAfterFree();
    incorrectFormatString();
    integerOverflow();
    fileNotClosed();
    compareFloats(1.23456789f, 1.23456788f);
    unreachableCode(5);
    unusedParameter(42, 100);
    infiniteLoop();
    missingBreakInSwitch(1);
    // ... remaining bug-invoking function calls ...
    return 0;
}
