#define _CRT_SECURE_NO_WARNINGS //чтобы не выдавало ошибку
#include <iostream>
#include <cstring>
using namespace std;

class String
{
private:
    char* data;
    size_t size;

public:
    String() : data(nullptr), size(0) {}

    String(const char* str)
    {
        size = strlen(str);
        data = new char[size + 1];
        strcpy(data, str);
    }

    String(const String& other)
    {
        size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
    }

    String& operator=(const String& other)
    {
        if (this == &other)
        {
            return *this;
        }
        delete[] data;
        size = other.size;
        data = new char[size + 1];
        strcpy(data, other.data);
        return *this;
    }

    String(String&& other) noexcept : data(other.data), size(other.size)
    {
        other.data = nullptr; 
        other.size = 0;
    }

    String& operator=(String&& other) noexcept
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

    ~String()
    {
        delete[] data;
    }

    // Вывод строки
    void print() const
    {
        if (data)
        {
            cout << data << endl;
        }
        else {
            cout << "Пустая строка" << endl;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    String str1("Hello");
    String str2 = move(str1); 

    str1.print();
    str2.print();

    return 0;
}