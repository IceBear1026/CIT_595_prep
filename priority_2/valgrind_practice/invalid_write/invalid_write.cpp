#include <iostream> 

int main() {
    int* arr = new int[3];

    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;

    // Bug: out-of-bounds write
    // arr[3] = 99;

    std::cout << "Done writing array." << std::endl;

    delete[] arr;
    // After deleting the array, arr becomes a dangling pointer. Accessing arr after this point would be undefined behavior. To avoid this, we can set arr to nullptr.
    arr = nullptr;

    return 0;
}