#include <iostream>
using namespace std;
size_t my_len = 5;
void AllocArray(int** arr, size_t len, int init_val);
int main() {
    int num = 3;
    int* array = nullptr;
    AllocArray(&array, my_len, num);
    delete[] array;
}

void AllocArray(int** arr, size_t len, int init_val) {
    int* new_arr = new int[len];
    for (size_t i = 0; i < len; ++i) {
        new_arr[i] = init_val;
    }
    *arr = new_arr;
    return;
}