#include <iostream>
using namespace std;

// strings in c are just arrays of characters with a special character at the end to mark the end of the string: '\0' (null terminator). This is how c knows where the string ends. The null terminator is a character with the value 0.

// C-strings are often referred to with a char[] or a char*. 
int main() {
    char c = '\0'; // null terminator
    char str[5] = "Rain"; // this is a c-string with 4 characters and a null terminator at the end. The size of the array is 5 to accommodate the null terminator.
    char* ptr_str = &(str[2]); // pointer to the 3rd character of the string (index 2)

    // So essentially you are creating a pointer in middle of the string character. And so if we referenced like ptr_str[0] it would be the 3rd character of the string. And if we referenced like ptr_str[1] it would be the 4th character of the string. And if we referenced like ptr_str[2] it would be the null terminator. 
    return 0;
};