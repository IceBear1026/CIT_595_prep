#include <iostream>
using namespace std;

struct Point {
    float first;
    float second;
};

int main() {
    const int x = 3;
    int y = 5;

    x += 1; // ILLEGAL
    y += 1; // LEGAL

    const Point p = {0.0, 0.0};

    p.first = 1.0; // ILLEGAL
    p.second = 2.0; // ILLEGAL

    return 0;
};
 