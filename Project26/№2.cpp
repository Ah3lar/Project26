#include <iostream>

class String {
private:
    char* data;
    size_t size;
    size_t capacity;

public:
    String(size_t initial_capacity = 10) : size(0), capacity(initial_capacity) {
        data = new char[capacity];
        data[0] = '\0';
    }

    ~String() {
        delete[] data;
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

    void append(char c) {
        if (size + 1 >= capacity) {
            reserve(capacity * 2);
        }
        data[size++] = c;
        data[size] = '\0';
    }

    void clear() {
        size = 0;
        data[0] = '\0';
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > capacity) {
            char* new_data = new char[new_capacity];
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }
            delete[] data;
            data = new_data;
            capacity = new_capacity;
        }
    }

    void shrink() {
        if (size < capacity) {
            reserve(size + 1);
        }
    }
};

int main() {
    String str;

    std::cout << "Size: " << str.getSize() << std::endl;
    std::cout << "Capacity: " << str.getCapacity() << std::endl;

    str.clear();
    std::cout << "Size after clear: " << str.getSize() << std::endl;

    str.reserve(50);
    std::cout << "Capacity after reserve: " << str.getCapacity() << std::endl;

    str.shrink();
    std::cout << "Capacity after shrink: " << str.getCapacity() << std::endl;

    return 0;
}
