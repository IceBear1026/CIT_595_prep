#include <iostream>
#include <cstring>

using namespace std;

struct String {
    char* data; // pointer to the car array (dynamic memory)
    size_t len; // length of the string (not including null terminator)
};

/*
regarding the input parameter char* new_data;

char new_data = one single character
char* new_data = pointer to an array of characters (a C-string like "hello")

Example:
when we call StringAppend(&str, "world"), we are passing a pointer to the whole string. 
*/
// char new_data = one single character
void StringAppend(String* str, char* new_data) {
    // we are creating a new_len because we need to create a new string that is the length of the old string + the length of the new string.
    int new_len = str->len + strlen(new_data);

    // we are creating a new array of characters that is the length of the new string + 1. So now we have new_data_array char pointer -> new array[] in heap memory.
    char* new_data_array = new char[new_len + 1]; // +1 for null terminator
    
    // we are copying the old string into the new array.
    /*
    We're saying:

    new_array = pointer to the new, bigger char array we just created
    str->data = pointer to the old char array (the one in the String struct)
    strcpy() = copies the content FROM str->data TO new_array
    So:
    Old array ("hello"):    h e l l o \0
                        ↑
                        str->data points here

    New array (bigger):     h e l l o \0 ? ? ? ? ?
                            ↑
                            new_array points here
                            (strcpy copies "hello" here)
    */
    strcpy(new_data_array, str->data);

    // strcat is used to concatenate the new string onto the end of the old string. It appends the content of new_data to new_data_array.
    strcat(new_data_array, new_data);

    // we are deleting the old string from memory to avoid memory leaks.
    // basically deleting an old pointer to a char array that is no longer needed.
    delete[] str->data;

    // we are updating the String struct to point to the new string and update the length.

    // again str->data is a pointer to the old char array, we are now updating it to point to the new char array.
    str->data = new_data_array;
    str->len = new_len;

}

String String_From(char* cstr) {
    String str;
    str.len = strlen(cstr);
    str.data = new char[str.len + 1];  // +1 for null terminator
    strcpy(str.data, cstr);
    return str;
}

/*
Question 1: What is argc and argv[0]?
When you run: ./program Hello World Test

argc = 4 (argument COUNT: the program name + 3 arguments)
argv[0] = "./program" (the program name itself)
argv[1] = "Hello"
argv[2] = "World"
argv[3] = "Test"

Which argument should we start with?
Answer: Start with argv[1], NOT argv[0]

Because argv[0] is just the program name. The actual arguments we want to concatenate start at argv[1].
*/

int main (int argc, char* argv[]) {
    /*
    write a main that takes all the args, adds them to one string, then prints them. Make sure you have no memory leaks or other errors. 
    
    You can assume you have access to String_From(char* cstr) which creates a String deep copying the passed in c-string.
    */

    String str = String_From(argv[1]); // create a String from the first argument. 

    // loop through the rest of the arguments and append them to the String.
    // We start at i = 2 because we already used argv[1] to create the initial String.
    for (int i = 2; i < argc; i++) {
        StringAppend(&str, argv[i]); // append each subsequent argument to the String.
    }

    // Print the final concatenated string.
    cout << str.data << endl;

    delete[] str.data; // free the memory allocated for the string to avoid memory leaks.

    return 0;
}