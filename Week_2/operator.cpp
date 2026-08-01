#include <iostream>

using namespace std;

class Point {
    public:
        // this is an initializer list for the constructor.
        Point(int x, int y) : m_x(x), m_y(y) {}

        // I understand we are creating a getter. But what is this "const"? 
        int GetX() const { return m_x; }
        int GetY() const { return m_y; }

        // this is an operator overload. We can modify the existing boolean operator to compare two points.The input parameter is constant meaning read only and we are getting alias meaning other is just naother name for whatever variable we receive so it will directly reference the object that gets passed into the function.
        bool operator==(const Point& other) const {
            return this->m_x == other.m_x && this->m_y == other.m_y;
        }
        
        // what this is doing is modifying the + operator. And since x and y are private member variables, we have to use a getter to get the values of each. And we are just returning Point{} but with direct values of x and y added together.
        Point operator+(const Point& lhs, const Point& rhs) {
            return Point{lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY()};
        }

        // this function is returning int& meaning it's returning a reference of an integer which is the actual value of the member variable. 
        // this is modifying [] operator to return the value of x or y depending on the index. 
        int& operator[](size_t index) {
            if (index == 0) {
                return this->m_x;
            }
            return this->m_y;
        }
    private:
        // these are the member variables of the class that gets created everytime you create it. 
        int m_x;
        int m_y;
};
int main () {

    return 0; 
}