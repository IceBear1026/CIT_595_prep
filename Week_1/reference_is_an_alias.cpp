#include <iostream>

using namespace std;

void funky (int val, int& ref) {
    val += 2;
    ref += 2;
}

int main() {
    int x = 5;
    int y = 10;

    // when we use reference like this, this is eseentially saying z is an alias for x. other words, z is another name for x. So if we change z, we are changing x. If we change x, we are changing z.
    int& z = x;

    z += 1;
    x += 1;

    z = y;
    z += 1;

    funky(x, y);

    return 0;
}

/*
*** Key Takeaways ***
The symbol & has different meanings depending on where it appears. 
1. In an expression: "Address of"
When & is placed before an existing variable in a normal code:
int x = 5;
int* ptr = &x; // &x means "the address of x"

&x here means "Give me the memory address of x".

x // int
&x // int*

2. In a declaration: "reference" or "alias"
When & is part of a variable or parameter declaration:
int& z = x;

It means: "Decalre z as a reference to x". Another name for x. 

It does not mean that z stores an address as a value. 
*/