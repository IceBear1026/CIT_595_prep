// std::forward_list is basically singly linked list in STL. 

#include <forward_list>
#include <algorithm>
#include <iostream>

void print_list(std::forward_list<int>& list);
int main() {
    // creates an empty singly linked list of integers
    std::forward_list<int> numbers;

    std::cout << "Is empty:  " << numbers.empty() << std::endl;

    // Adds values to the FRONT of the list.
    numbers.push_front(30);
    numbers.push_front(20);
    numbers.push_front(10);

    // the list is now:
    // head -> 10 -> 20 -> 30 -> nullptr

    std::cout << "Values: ";

    // so I can do a for loop like this to print out the singly forward linked ist. 
    print_list(numbers);

    // gets the value at the front node.
    std::cout << "Front value: " << numbers.front() << std::endl;

    // removes the front node.
    numbers.pop_front();

    std::cout << "Values after pop_front: ";
    for (auto itr = numbers.begin(); itr != numbers.end(); ++itr) {
        std::cout << *itr << ' ';
    }

    // // important meanings
    // numbers.begin(); // returns an iterator to the first element in the list. 
    // numbers.end(); // returns an iterator to the element following the last element in the list. 

    // A singly linked list naturally inserts AFTER an existing position. 

    auto first_position = numbers.begin(); // points to the first element in the list (20)

    numbers.insert_after(first_position, 25); // inserts 25 after the first element (20)

    std::cout << '\n';
    std::cout << "Values after insert_after: ";
    print_list(numbers);

    // let's make the list to 10 -> 20 -> 25 -> 30 -> nullptr
    numbers.insert_after(numbers.before_begin(), 10); // inserts 10 after the head (which is now 20)
    // The reason why we have to use before_begin() is because we want to insert 10 at the beginning of the list. And since we don't have "head" pointer, we have to use before_begin() to get the position before the first element. 
    // if I wanted to use the head concept, I would have to use a pointer to the first element, which is not available in std::forward_list.
    print_list(numbers);

    // remove the node after a position
    auto position = numbers.begin(); // points to the first element in the list (10)
    numbers.erase_after(position); // removes the node after the position (which is 20)

    print_list(numbers);

    // front() and pop_front() are the only two functions that can be used to access or remove the first element of the list.

    std::cout << numbers.front() << std::endl; // this will print the value of the first element in the list.
    std::cout << &(*numbers.begin()) << std::endl; // this will print the address of the first element in the list.

    // You can also modify the head value. 
    numbers.front() = 99;

    print_list(numbers);

    // remove the head
    numbers.pop_front(); // removes the first element in the list (which is 99)

    print_list(numbers);

    numbers.insert_after(numbers.before_begin(), 35); // inserts 35 

    print_list(numbers);

    /* =========================================== */
    auto iterator = numbers.begin();

    std::cout << "First: " << *iterator << '\n';

    ++iterator;

    std::cout << "Second: " << *iterator << '\n';

    /* =========================================== */
    // find a particular value
    auto result = std::find(numbers.begin(), numbers.end(), 25);

    if(result != numbers.end()) {
        std::cout << "Found: " << *result << '\n';
    } else {
        std::cout << "Not found" << '\n';
    }
    /* =========================================== */
    std::forward_list<int> list1 = {10, 20, 10, 30};
    list1.remove(10); // removes all elements with value 10
    print_list(list1);

    // you can also use a condition
    std::forward_list<int> list2 = {10, 20, 10, 30, 40, 50};
    list2.remove_if([](int value) { return value > 20;}); // removes all elements with value greater than 20
    print_list(list2);

    // the lambda:
    // [](int value) { return value > 20;} is a lambda function that takes an int value and returns true if the value is greater than 20, false otherwise.
    /* 
    lambda syntax:
    [capture](parameters) -> return_type { body }

    [] Capture list controls whether the lambda can access variables declared outside of the lambda. Empty brackets mean do not capture any outside variables. But if I had to give an example that is not empty, I could do something like this:
    int x = 10;
    std::forward_list<int> list3 = {10, 20, 10, 30, 40, 50};
    list3.remove_if([x](int value) { return value > x;}); // removes all elements with value greater than x (10)

    Your lambda behaves similarly to this regular function:

    bool greater_than_20(int value) {
        return value > 20;
    }

    You could then write:

    list1.remove_if(greater_than_20);
    */

    // reverse the list
    numbers.reverse();
    list1.reverse();
    list2.reverse();
    print_list(numbers);
    print_list(list1);
    print_list(list2);

    // clear the whole lsit
    numbers.clear();
    list1.clear();
    list2.clear();

    return 0;
}

void print_list(std::forward_list<int>& list) {
    for (int value : list) {
        std::cout << value << ' ';
    }
    std::cout << '\n';
    // for (auto itr = numbers.begin(); itr != numbers.end(); ++itr) {
    //     std::cout << *itr << ' ';
    // }
}