#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

void modify_point (Point* ptr) {
    ptr->x = 3800;
    ptr->y = 4710;
}

int main() {
    Point p{1100, 2400};
    modify_point(&p);

    cout << p.x << ", " << p.y << endl;
    return 0;
}

/*
Why not this->x?

You only use this inside a member function belonging to a class or struct.

For example:

struct Point {
    int x;
    int y;

    void modify() {
        this->x = 3800;
        this->y = 4710;
    }
};

Then:

Point p{1100, 2400};
p.modify();

Inside modify(), this points to the particular Point object that called the function.
*/