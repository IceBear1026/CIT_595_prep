#include <cstdlib>
#include <iostream>

int global_initialized = 10;
int global_zero_initialized;

int main() {
    static int static_value = 20;
    int stack_value = 30;
    int* heap_value = new int(40);

    std::cout << "main code:          "
              << reinterpret_cast<const void*>(&main) << '\n';

    std::cout << "global initialized: " << &global_initialized << '\n';
    std::cout << "global zero-init:   " << &global_zero_initialized << '\n';
    std::cout << "static value:       " << &static_value << '\n';
    std::cout << "stack value:        " << &stack_value << '\n';
    std::cout << "heap object:        " << heap_value << '\n';
    std::cout << "pointer variable:   " << &heap_value << '\n';

    delete heap_value;
    return EXIT_SUCCESS;
}