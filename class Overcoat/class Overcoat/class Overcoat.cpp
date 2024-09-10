#include <iostream>
#include <string>
using namespace std;

class Overcoat
{
private:
    string type;
    double price;

public:
    Overcoat(const string& type, double price) : type(type), price(price) {}

    bool operator==(const Overcoat& other) const
    {
        return type == other.type;
    }

    Overcoat& operator=(const Overcoat& other)
    {
        if (this != &other)
        {
            type = other.type;
            price = other.price;
        }
        return *this;
    }

    bool operator>(const Overcoat& other) const
    {
        if (type == other.type)
        {
            return price > other.price;
        }
        return false; // Сравнение некорректно, если типы разные
    }

    void display() const
    {
        cout << "Тип: " << type << ", Цена: " << price << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Overcoat coat1("Шерсть", 200.0);
    Overcoat coat2("Кожа", 350.0);
    Overcoat coat3("Шерсть", 150.0);

    cout << "Пальто 1: ";
    coat1.display();

    cout << "Пальто 2: ";
    coat2.display();

    cout << "Пальто 3: ";
    coat3.display();

    if (coat1 == coat3)
    {
        cout << "Пальто 1 и Пальто 3 одного типа." << endl;
    }
    else
    {
        cout << "Пальто 1 и Пальто 3 бывают разных типов." << endl;
    }

    coat2 = coat1;
    cout << "Пальто 2 после присваивания: ";
    coat2.display();

    if (coat1 > coat3)
    {
        cout << "Пальто 1 дороже, чем Пальто 3." << endl;
    }
    else
    {
        cout << "Пальто 3 дороже, чем Пальто 1, или они имеют одинаковую цену." << endl;
    }

    return 0;
}
