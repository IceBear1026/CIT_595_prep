#include <iostream>

using namespace std;
struct Point {
    float x;
    float y;
};

int main() {
    Point pt;
    Point origin = {0.0f, 0.0f};

    pt = origin; // copying the values of origin into pt

    origin.x = 1.0f; // modifying origin's x value

    cout << origin.x << endl; // prints 1.0
    cout << pt.x << endl; // prints 0.0, because pt is a copy of origin, not a reference

    return 0;
}
