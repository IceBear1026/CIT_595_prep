#include <iostream>

using namespace std;

typedef struct point_st {
    int x;
    int y;
} Point;

void modify_point (Point* ptr) {
    Point new_point = (Point) {
        .x = 3800,
        .y = 4710,
    };
    *ptr = new_point;
}

int main() {
    Point p = {1100, 2400};
    modify_point(&p);
    printf("&d, &d\n", p.x, p.y);
    return EXIT_SUCCESS;
}