#include <iostream>

using namespace std;

class Flat
{
private:
    double area;
    double price;

public:
    Flat(double area, double price) : area(area), price(price) {}

    bool operator==(const Flat& other) const
    {
        return area == other.area;
    }

    Flat& operator=(const Flat& other)
    {
        if (this != &other)
        {
            area = other.area;
            price = other.price;
        }
        return *this;
    }

    bool operator>(const Flat& other) const
    {
        return price > other.price;
    }

    void display() const
    {
        cout << "Площадь: " << area << ", Цена: " << price << endl;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    Flat flat1(50.0, 100000.0);
    Flat flat2(60.0, 120000.0);
    Flat flat3(50.0, 110000.0);

    cout << "Квартира 1: ";
    flat1.display();

    cout << "Квартира 2: ";
    flat2.display();

    cout << "Квартира 3: ";
    flat3.display();

    if (flat1 == flat3)
    {
        cout << "Квартира 1 и Квартира 3 иметь одинаковую площадь." << endl;
    }
    else
    {
        cout << "Квартира 1 and Квартира 3 имеют разные площади." << endl;
    }

    flat2 = flat1;
    cout << "Квартира 2 после присваивания: ";
    flat2.display();

    if (flat1 > flat3)
    {
        cout << "Квартира 1 дороже чем Квартира 3." << endl;
    }
    else
    {
        cout << "Квартира 3 дороже, чем Квартира 1, или они имеют одинаковую цену." << endl;
    }

    return 0;
}
