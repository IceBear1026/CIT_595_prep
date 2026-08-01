#include <iostream> 

using namespace std;

struct string_view {
    char* data;
    size_t len;

    // constructor
    string_view(char* cstr); 

    // member function to get the length of the string
    size_t length();
};

// string_view::string_view(char* cstr) {
//     data = cstr;
//     len = strlen(cstr);
// }

// The above and the below are the same constructors. But the below is more efficient because it uses the member initializer list to initialize the data members directly, rather than assigning values in the constructor body.

/*
An example:
struct Example {
    int value;

    Example(int input) : value(input){}
};
*/

string_view::string_view(char* cstr) : data(cstr), len(strlen(cstr)){}

size_t string_view::length() {
    return this->len;
}

int main () {
    string_view view{"hello"};

    cout << view.data << endl;
    cout << view.length() << endl;

    return 0; 
}