#include <iostream>

using namespace std;

// mat is an array of rows.
// Each row is a nullptr-terminated array of char* pointers.
//
// len is the number of rows.
//
// Returns a newly allocated, nullptr-terminated array
// containing all char* pointers from all rows.
char** flatten(char*** mat, size_t len) {
    // the reason why we are starting with 1 is, 
    size_t new_len = 1;

    // We are for looping the mat which contains the rows (double pointers) that contains the char* pointers (string char arrays). 
    // We are counting the number of char* pointers in each row and adding them to new_len to get the total number of char* pointers in the flattened array.
    for (size_t i = 0; i < len; ++i) {
        size_t j = 0;
        while (mat[i][j] != nullptr) {
            ++j;
        }
        new_len += j;
    }

    char** new_arr = new char*[new_len];

    // copy the char* over
    size_t arr_index = 0;
    for (size_t i = 0; i < len; ++i) {
        size_t j = 0;
        while (mat[i][j] != nullptr) {
            new_arr[arr_index] = mat[i][j];
            arr_index += 1;
            j += 1;
        }
    }

    new_arr[new_len - 1] = nullptr;
    return new_arr;
}

int main() {
    // These are writable character arrays stored in main's stack frame.
    char apple[] = "apple";
    char banana[] = "banana";
    char cat[] = "cat";
    char dog[] = "dog";
    char fish[] = "fish";

    // Each row is an array of char* pointers.
    // Each row must end with nullptr.
    char* row1[] = {
        apple,
        banana,
        nullptr
    };

    char* row2[] = {
        cat,
        dog,
        fish,
        nullptr
    };

    // mat is an array of char** rows.
    //
    // mat[0] -> row1
    // mat[1] -> row2
    char** mat[] = {
        row1,
        row2
    };

    size_t row_count = 2;

    char** flattened = flatten(mat, row_count);

    if (flattened == nullptr) {
        cerr << "Flatten failed." << endl;
        return 1;
    }

    // The flattened array also ends with nullptr.
    size_t index = 0;

    while (flattened[index] != nullptr) {
        cout << flattened[index] << endl;
        ++index;
    }

    // flatten allocated the pointer array using new char*[...].
    // Therefore, release that array using delete[].
    delete[] flattened;
    flattened = nullptr;

    return 0;
}