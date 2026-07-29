#include <iostream>

int* arr_copy(int* to_duplicate, size_t len);

int main() {
    int original[3] = {10, 20, 30};
    int* duplicated = arr_copy(original, 3);

    delete[] duplicated;
    duplicated = nullptr;
    return 0;
}

int* arr_copy(int* to_duplicate, size_t len) {
    int* copy = new int[len];
    for (size_t i = 0; i < len; ++i) {
        copy[i] = to_duplicate[i];
    }
    return copy;
}