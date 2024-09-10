#include <iostream>
#include <Windows.h>
using namespace std;

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int numerator = 0, int denominator = 1)
    {

        if (denominator == 0)
        {
            throw invalid_argument("Знаменатель не может быть нулевым.");
        }
        this->numerator = numerator;
        this->denominator = denominator;
        simplify();
    }

    // Метод для упрощения дроби
    void simplify()
    {
        int gcd = greatestCommonDivisor(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0)
        {
            numerator *= -1;
            denominator *= -1;
        }
    }

    // Перегрузка оператора +
    Fraction operator+(const Fraction& other) const
    {
        int newNumerator = numerator * other.denominator + denominator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // Перегрузка оператора -
    Fraction operator-(const Fraction& other) const
    {
        int newNumerator = numerator * other.denominator - denominator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // Перегрузка оператора *
    Fraction operator*(const Fraction& other) const
    {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // Перегрузка оператора /
    Fraction operator/(const Fraction& other) const
    {
        if (other.numerator == 0)
        {
            throw invalid_argument("Невозможно разделить на ноль.");
        }
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    // Перегрузка оператора << для вывода дроби
    friend ostream& operator<<(ostream& out, const Fraction& fraction)
    {
        out << fraction.numerator << "/" << fraction.denominator;
        return out;
    }

private:
    // Метод для вычисления наибольшего общего делителя
    int greatestCommonDivisor(int a, int b) const
    {
        while (b != 0)
        {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    try
    {
        Fraction f1(3, 4);
        Fraction f2(1, 2);
        cout << "Дробь 1: " << f1 << "," << endl;
        cout << "Дробь 2: " << f2 << endl;
        Sleep(1000);
        cout << "Подсчёт...." << endl;
        Sleep(2000);

        Fraction sum = f1 + f2;
        cout << "f1 + f2: " << sum << endl;

        Fraction difference = f1 - f2;
        cout << "f1 - f2: " << difference << endl;

        Fraction product = f1 * f2;
        cout << "f1 * f2: " << product << endl;

        Fraction quotient = f1 / f2;
        cout << "f1 / f2: " << quotient << endl;
    }
    catch (const exception& e)
    {
        cerr << "Ошибка: " << e.what() << endl;
    }
    return 0;
}
