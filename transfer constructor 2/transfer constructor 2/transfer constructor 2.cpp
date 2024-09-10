#include <iostream>
#include <utility> // для std::move
using namespace std;

class Array
{
private:
    int* data;
    size_t size;

public:
    Array() : data(nullptr), size(0) {}

    Array(size_t size) : size(size)
    {
        data = new int[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = 0;
        }
    }

    Array(const Array& other)
    {
        size = other.size;
        data = new int[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
    }

    Array& operator=(const Array& other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] data;
        size = other.size;
        data = new int[size];
        for (size_t i = 0; i < size; ++i)
        {
            data[i] = other.data[i];
        }
        return *this;
    }

    Array(Array&& other) noexcept : data(other.data), size(other.size)
    {
        other.data = nullptr;
        other.size = 0;
    }

    Array& operator=(Array&& other) noexcept
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] data;
        data = other.data;
        size = other.size;

        other.data = nullptr;
        other.size = 0;

        return *this;
    }

    ~Array()
    {
        delete[] data;
    }

    void print() const
    {
        if (data)
        {
            for (size_t i = 0; i < size; ++i)
            {
                cout << data[i] << " ";
            }
            cout << endl;
        }
        else
        {
            cout << "Пустой массив" << endl;
        }
    }

    void set(size_t index, int value)
    {
        if (index < size)
        {
            data[index] = value;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Array arr1(5);
    arr1.set(0, 10);
    arr1.set(1, 20);
    arr1.set(2, 30);
    arr1.set(3, 40);
    arr1.set(4, 50);

    cout << "массив 1: ";
    arr1.print();

    Array arr2 = move(arr1);

    cout << "массив 1 после перемещения: ";
    arr1.print();

    cout << "массив 2: ";
    arr2.print();

    return 0;
}