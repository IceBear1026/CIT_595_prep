#include <iostream>

int main() {
    int* value = new int(10);

    std::cout << "Value is: " << *value << std::endl;

    // Bug: forgot delete value;

    // Fix: delete value to free memory
    delete value;
    // Set pointer to nullptr to avoid dangling pointer
    value = nullptr;

    // dangling pointers are pointers that point to memory that has been freed, which can lead to undefined behavior if accessed. And can technically cause crashes or other unexpected behavior if dereferenced. And can cause vulnerabilities in the program if exploited. How? If an attacker can manipulate the program to dereference a dangling pointer, they could potentially read or write arbitrary memory locations, leading to security issues. More specifically, if the program later uses the dangling pointer, it might read stale data or overwrite memory that it shouldn't, which could be exploited to execute arbitrary code or corrupt program state.

    return 0;
}
// compile it: g++ -std=c++20 -Wall -Wextra -Wpedantic -g leak.cpp -o leak
