#include <iostream>
#include <cstring>

using namespace std;

struct SimpleString {
    char* data;
    size_t len;
}

SimpleString SimpleString_From(const char* cstring) {
    SimpleString ret;
    char* arr = new char[strlen(cstring) + 1];
    for (size_t i = 0; i <= strlen(cstring); i++) {
        arr[i] = cstring[i];
    }
    ret.data = arr;
    ret.len = strlen(cstring);
    return ret;
}

SimpleString ToUpper(SimpleString s) {
    // issue* res and s point to the same memory address. So modifying res.data also modifies s.data. This is a problem because we want to keep the original string intact. To fix this, we need to create a new SimpleString object and allocate new memory for its data.
    SimpleString res;
    res.data = new char[s.len + 1]; // allocate new memory for the new string
    for (size_t i = 0; i < s.len; ++i) {
        // convert each char to uppercase
        // toupper does what you think it does
        res.data[i] = toupper(s.data[i]);
    }
    res.len = s.len;
    res.data[s.len] = '\0'; // null-terminate the new string
    return res;
}
int main() {
    SimpleString hi = SimpleString_From("Hello");
    SimpleString up = ToUpper(hi);

    cout << hi.data << endl;
    cout << up.data << endl;

    // we are delete[] because we used new[] to allocate the memory for the char array. And when creating a new array and use "new" we are writing into heap hence we have to manually free the memory using delete[].
    delete[] hi.data;
    delete[] up.data;

    return 0;
}