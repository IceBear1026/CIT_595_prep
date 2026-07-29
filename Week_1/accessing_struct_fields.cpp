#include <iostream>

using namespace std;
struct Point {
    float x;
    float y;
};

// argc is the number of command line arguments
// argv is an array of C-style strings (char*) representing the command line arguments
int main(int argc, char** argv) {
    Point p1 = {0.0, 0.0};
    Point* p1_ptr = &p1; // p1_ptr is a pointer to p1. We use &p1 because & will give the address of p1

    p1.x  = 1.0; // modifying p1's x value
    p1_ptr->y = 2.0; // modifying p1's y value using the pointer. We use -> because p1_ptr is a pointer to a struct 
    // same thing as (*p1_ptr).y = 2.0;

    // so there are two ways to access the fields of a struct: using the dot operator (.) and using the arrow operator (->) when you have a pointer to a struct

    return 0;
}
