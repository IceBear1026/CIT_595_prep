// hash_table = unordered_map
#include <iostream>
#include <unordered_map>

int main() {
    // First int = key type
    // Second int = value type

    std::unordered_map<int, int> hash_map;

    // Insert key-value pairs into the hash_map
    hash_map[1] = 100;
    hash_map[2] = 200;
    hash_map[3] = 300;

    std::cout << "Key 1 has value: " << hash_map[1] << '\n';
    std::cout << "Key 2 has value: " << hash_map[2] << '\n';

    // Key 1 already exists, so this replaces its old value.
    hash_map[1] = 999;

    std::cout << "Updated key 1: " << hash_map[1] << '\n';
    std::cout << "Number of keys: " << hash_map.size() << '\n';

    return 0;
}