#include <iostream>

int main() {
    int* arr = new int[2];
    // can I do without *? 
    int arr1 = new int[2];
    // can I do without *? no, because new int[2] returns a pointer to the first element of the array, and you need to store that pointer in a variable. If you try to assign it to an int variable (like arr1), it will result in a type mismatch error since arr1 is not a pointer type.
    return 0;
}