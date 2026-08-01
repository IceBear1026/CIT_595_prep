#include <cstddef>
#include <iostream>
#include <utility> // std::move

using namespace std;

class Buffer {
    public:
        // what is explicit? 
        // we are creating initializer list constructor.
        explicit Buffer(size_t size) : m_data(size > 0? new int[size] : nullptr), m_size(size) {
            for(size_t i = 0; i < m_size; ++i) {
                m_data[i] = 0; 
            }

            cout << "Normal constructor\n";
        }

        // I don't knwo what static_const means
        ~Buffer() {
            cout << "Destructor freeing: " << static_cast<const void*>(m_data) << '\n'; 

            delete[] m_data;
        }
}



int main() {
}