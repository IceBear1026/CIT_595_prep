#include <iostream>

using namespace std;

struct Leaky {
    int *x;
};

int main(int argc, char** argv) {
    // So lkyptr points to a heap slot that can store a Leaky pointer. 
    Leaky **lkyptr = new Leaky*();
    /*
    Heap:

    slot A (type Leaky*) = null
    Arrow:

    lkyptr -> slot A
    */

    // lky (type Leaky*) points to a heap slot that can store a Leaky struct.
    // lkyptr (type Leaky**) points to a heap slot that can store a Leaky pointer.  
    Leaky *lky = new Leaky();
    lky->x = new int(5);

    // Essentially we are dereferencing the lkyptr double pointer to its pointed pointer to store the address of lky pointer address which makes *lkyptr to also point towards the same heap slot as lky.
    *lkyptr = lky;
    // Delete in reverse ownership order: inner allocation first, then struct, then pointer-to-pointer.

    // Frees the heap int object created by new int(5). That includes the memory cell that currently stores value 5. So no, the 5 does not remain allocated after this. 
    delete lky->x;

    // This frees the heap Leaky object created by new Leaky. 
    delete lky;

    // This frees the heap slot created by new Leaky*(). The pointer holder. 
    // This does not delete the Leaky object that stored pointer value refers to. 
    // **Leaky pointer -> *Leaky pointer -> Leaky object -> int object. 
    delete lkyptr;

    return EXIT_SUCCESS;
}