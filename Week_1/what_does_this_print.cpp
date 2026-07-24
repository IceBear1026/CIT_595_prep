#include <iostream>

using namespace std;
int main() {
    int curr = 6;
    int arc = 12;

    int* ptr = &curr;
    *ptr = 2;
    arc = 3;

    int** other = &ptr;
    ptr = &arc;
    **other = curr;
    *other += 3;

    cout << curr << " " << arc << " " << ptr << endl;
    
    return 0;
}