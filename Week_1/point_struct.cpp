#include <iostream>

/*
A collection of related variables of different types (and potentially operations)

All members of a struct are public by default. 

A struct may have referential types within it, but those fields are passed by value.
*/

using namespace std;

struct Point {
    double x;
    double y;
    char* name;
};

double dot_prod(Point a, Point b) {
    // we can just get a copy of the struct because we are not trying to change anything but just use the value. 
    return a.x * b.x + a.y * b.y;
}

int main() {
    Point p1 = {1.0, 3.5, "hello"};
    Point p2 = {2.0, 7.5, "hi"};

    cout << dot_prod(p1, p2) << endl;

    exit(EXIT_SUCCESS);
}