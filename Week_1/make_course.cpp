#include <iostream>
#include <cstring>

using namespace std;

struct Course {
    char* dept;
    unsigned int num;
};

// when calling function it would look like this: MakeCourse("CS", 101);
Course MakeCourse(char* dept, int num) {
    Course res;
    /*
    I can do this as well.
    auto* ptr = &res;
    ptr->dept = dept;
    ptr->num = num;
    */

    // res is a struct variable (not a pointer), so you use the dot operator. 
    res.dept = dept;
    res.num = num;
    return res;
}

void FixCourse(Course* to_fix) {
    size_t len = strlen(to_fix->dept);
    for (size_t i = 0; i < len; i++) {
        to_fix->dept[i] = toupper(to_fix->dept[i]);
    }
    to_fix->num *= 10;
}

int main () {
    char cis[] = "cis";
    char rees[] = "rees";

    //  You don't need &rees here. When you pass AN ARRAY to a function, it automatically decays to a pointer to the first element of the array. 
    Course ser = MakeCourse(rees, 0275);

    Course me;
    me.dept = cis;
    me.num = 399;

    FixCourse(&ser);
    FixCourse(&me);

    cout << ser.dept << ser.num << endl;
    cout << me.dept << me.num << endl;

    return 0;
}