#include <cstring>
#include <iostream>
#include <map>
#include <mutex>
#include <stdio.h>
#include <string.h>
#include <vector>
// 16. Buffer overflow
void bufferOverflow() {
  char buffer[5];
  strcpy(buffer, "Overflowed text"); // Buffer overflow (High severity)
}

// 17. Infinite recursion
void infiniteRecursion(int x) {
  if (x == 0) {
    return;
  }
  infiniteRecursion(x); // Infinite recursion (High severity)
}

// 18. Uninitialized class member
class MyClass {
public:
  int value; // Uninitialized class member (High severity)
  MyClass() {}
};

// 19. Unhandled exception
void throwUnhandledException() { throw "Unhandled exception!"; }

// 20. Use of mismatched data types
void mismatchedDataTypes() {
  int num = 42;
  double result =
      num + 3.14; // Mixing int and double without explicit cast (High severity)
}

// 21. Incorrect use of dynamic_cast
class Base {
public:
  virtual ~Base() {}
};
class Derived : public Base {};

void incorrectUseOfDynamicCast() {
  Base *basePtr = new Base();
  Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);
  if (derivedPtr != nullptr) {
    std::cout << "Dynamic cast successful." << std::endl;
  }
}

// 22. Double-locking for mutex
std::mutex mtx;
void doubleLock() {
  mtx.lock();
  mtx.lock(); // Double-locking (High severity)
  // Do something critical
  mtx.unlock();
  mtx.unlock();
}

// 23. Incorrect use of std::string::substr
#include <string>
void incorrectUseOfStringSubstr() {
  std::string str = "Hello, World!";
  std::string substr =
      str.substr(7, 5); // Incorrect substring length (High severity)
  std::cout << substr << std::endl;
}

// 24. Missing return in non-void function
int missingReturnInNonVoidFunction(bool flag) {
  if (flag) {
    return 42;
  }
  // Missing return statement here (High severity)
}

// 25. Incorrect use of std::map
void incorrectUseOfMap() {
  std::map<int, int> myMap;
  myMap[42]; // Creates a new entry with value 0 (High severity)
}

// ... 5 more bugs, making a total of 30 bugs ...

int main() {
  bufferOverflow();
  infiniteRecursion(5);
  MyClass obj;
  std::cout << "Uninitialized class member: " << obj.value << std::endl;
  throwUnhandledException();
  mismatchedDataTypes();
  incorrectUseOfDynamicCast();
  doubleLock();
  incorrectUseOfStringSubstr();
  missingReturnInNonVoidFunction(true);
  incorrectUseOfMap();
  // ... remaining bug-invoking function calls ...
  return 0;
}
