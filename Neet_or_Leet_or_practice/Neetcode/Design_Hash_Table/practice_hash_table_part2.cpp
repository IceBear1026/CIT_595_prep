#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

void printTable(unordered_map<int, string>& table) {
    for (auto& [key, value] : table) {
        cout << key << "->" << value << '\n';
    }
}
// question for printTable. Does & make the input parameter basically change the actual object that is being passed into the function? Yes, the `&` in the function parameter `unordered_map<int, string>& table` indicates that the parameter is being passed by reference. This means that the function receives a reference to the original object rather than a copy of it. As a result, any modifications made to `table` within the `printTable` function will affect the original unordered_map that was passed in.
// Also during for loop, the reason why we have & in 'auto& [key, value]' is to avoid copying the key-value pairs. By using a reference, we can access the original elements in the unordered_map without creating unnecessary copies, which can improve performance, especially for larger data structures.

int main() {
    unordered_map<int, string> table;

    table[1] = "one";
    table[2] = "two";
    table[3] = "three";

    cout << "Initial table:\n";
    printTable(table);

    table[2] = "updated two";

    cout << "\nAfter update:\n";
    printTable(table);

    if (table.contains(2)) {
        cout << "\nKey 2 exists in the table.\n";
    }

    // contains(value) is for C++20 and above. If you are using C++17 or below, you can use find() instead of contains() to check if a key exists in the unordered_map. The find() function returns an iterator to the element if it is found, or table.end() if it is not found.

    auto result = table.find(3);

    // so find will loop through the whole map and eventually if it's not found, it will end at table.end(). Hence, we are using this to check whether or not the find was successful. If it was successful, then we can access the value of the key-value pair by using result->second. If it was not successful, then we can just return table.end() which is basically a pointer to the end of the map.   
    if (result != table.end()) {
        cout << "Found" << endl;
        cout << "Key: " << result->first << endl;
        cout << "Value: " << result->second << endl;
    }

    bool removed = table.erase(1) == 1; // erase returns the number of elements removed, so if it is 1, then we know that the key was found and removed. If it is 0, then we know that the key was not found and nothing was removed. But what is if it's larger than 1? In an unordered_map, keys are unique, so the erase function will only remove one element at most. Therefore, the return value of erase will always be either 0 (if the key was not found) or 1 (if the key was found and removed). It cannot be larger than 1 because there cannot be multiple elements with the same key in an unordered_map.

    cout << boolalpha; // this will make the output of boolean values to be printed as true or false instead of 1 or 0. It's a built-in manipulator in C++ that changes the way boolean values are displayed in the output stream.

    cout << "Removed key 1: " << removed << '\n';

    // The size() function returns the number of key-value pairs in the unordered_map. It is a constant time operation, meaning it takes the same amount of time regardless of the size of the unordered_map. This is because the unordered_map maintains a count of its elements internally, so it can return the size directly without having to iterate through the elements.
    cout << "Size: " << table.size() << '\n';

    // The bucket_count() function returns the number of buckets in the unordered_map. A bucket is a container that holds elements that hash to the same value. The unordered_map uses a hash function to determine which bucket an element belongs to based on its key. The number of buckets can affect the performance of the unordered_map, as having too few buckets can lead to more collisions and slower access times, while having too many buckets can waste memory. The bucket_count() function allows you to see how many buckets are currently being used by the unordered_map. 
    // I'm stil confused about the difference between size() and bucket_count(). The size() function returns the number of key-value pairs in the unordered_map, while the bucket_count() function returns the number of buckets in the unordered_map. The size() function tells you how many elements are currently stored in the unordered_map, while the bucket_count() function tells you how many buckets are being used to store those elements. The number of buckets can affect the performance of the unordered_map, as having too few buckets can lead to more collisions and slower access times, while having too many buckets can waste memory. The bucket_count() function allows you to see how many buckets are currently being used by the unordered_map. 
    // Is it similar to size and capacity in vector? Yes, the concept is somewhat similar. In a vector, size() returns the number of elements currently stored in the vector, while capacity() returns the amount of space that has been allocated for the vector, which may be larger than the current size. In an unordered_map, size() returns the number of key-value pairs currently stored, while bucket_count() returns the number of buckets that have been allocated to store those elements. Both concepts relate to how much space is being used versus how much space is available for future growth.
    cout << "Buckets: " << table.bucket_count() << '\n';

    cout << "Load factor: " << table.load_factor() << '\n'; 
    // The load_factor() function returns the average number of elements per bucket in the unordered_map. It is calculated as the size of the unordered_map divided by the number of buckets. A higher load factor indicates that there are more elements per bucket, which can lead to more collisions and slower access times. A lower load factor indicates that there are fewer elements per bucket, which can lead to faster access times but may waste memory. The load_factor() function allows you to see how efficiently the unordered_map is using its buckets.

    cout << table.at(2) << '\n';
    // this prints "updated two" because the key 2 is still in the unordered_map. The at() function is used to access the value associated with a specific key in the unordered_map. If the key does not exist, it will throw an out_of_range exception. In this case, since we have not removed key 2 from the unordered_map, calling table.at(2) will return the value "updated two" that is associated with key 2.

    // You can also update an existing value:
    table.at(3) = "updated three"; // This will update the value associated with key 3. The at() function checks if the key exists in the unordered_map before trying to access its value. Since key 3 exists, calling table.at(3) will return a reference to the value, allowing it to be updated.

    // so instead of using table[3] = "updated three"; we can use table.at(3) = "updated three";. The difference is that table[3] will insert a new key-value pair if key 3 does not exist, while table.at(3) will throw an exception if key 3 does not exist. Therefore, using at() is safer when you want to ensure that the key exists before updating its value.

    // using insert()
    table.insert({4, "four"}); 
    // The insert() function is used to add a new key-value pair to the unordered_map. In this case, we are inserting the key 4 with the value "four". If the key already exists in the unordered_map, the insert() function will not update the existing value; it will simply do nothing. This is different from using the subscript operator (table[4] = "four"), which would overwrite the existing value if the key already exists.

    return 0;
}
