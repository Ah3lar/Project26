#include <iostream>

template <typename T>
class Array {
private:
    T* data;
    size_t size;
    size_t capacity;

public:
    Array(size_t initial_capacity = 10) : size(0), capacity(initial_capacity) {
        data = new T[capacity];
    }

    ~Array() {
        delete[] data;
    }

    size_t getSize() const {
        return size;
    }

    size_t getCapacity() const {
        return capacity;
    }

    void append(const T& value) {
        if (size >= capacity) {
            reserve(capacity * 2);
        }
        data[size++] = value;
    }

    void erase(size_t index) {
        if (index < size) {
            for (size_t i = index; i < size - 1; ++i) {
                data[i] = data[i + 1];
            }
            --size;
        }
    }

    void clear() {
        size = 0;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > capacity) {
            T* new_data = new T[new_capacity];
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
            reserve(size);
        }
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }
};

int main() {
    Array<int> arr;

    arr.append(10);
    arr.append(20);
    arr.append(30);

    std::cout << "Size: " << arr.getSize() << std::endl;
    std::cout << "Capacity: " << arr.getCapacity() << std::endl;

    arr.erase(1);
    std::cout << "Size after erase: " << arr.getSize() << std::endl;

    arr.clear();
    std::cout << "Size after clear: " << arr.getSize() << std::endl;

    arr.reserve(20);
    std::cout << "Capacity after reserve: " << arr.getCapacity() << std::endl;

    arr.shrink();
    std::cout << "Capacity after shrink: " << arr.getCapacity() << std::endl;

    return 0;
}
