#include <iostream>
#include <cmath>
#include <Windows.h>
using namespace std;

class Complex
{
private:
    double real;
    double imaginary;

public:
    Complex(double real = 0.0, double imaginary = 0.0)
        : real(real), imaginary(imaginary) {}

    // Перегрузка оператора +
    Complex operator+(const Complex& other) const
    {
        return Complex(real + other.real, imaginary + other.imaginary);
    }

    // Перегрузка оператора -
    Complex operator-(const Complex& other) const
    {
        return Complex(real - other.real, imaginary - other.imaginary);
    }

    // Перегрузка оператора *
    Complex operator*(const Complex& other) const
    {
        return Complex(real * other.real - imaginary * other.imaginary,
            real * other.imaginary + imaginary * other.real);
    }

    // Перегрузка оператора /
    Complex operator/(const Complex& other) const
    {
        double denominator = other.real * other.real + other.imaginary * other.imaginary;
        if (denominator == 0)
        {
            throw invalid_argument("Нельзя делить на ноль.");
        }
        return Complex((real * other.real + imaginary * other.imaginary) / denominator,
            (imaginary * other.real - real * other.imaginary) / denominator);
    }

    // Перегрузка оператора << для вывода комплексного числа
    friend ostream& operator<<(ostream& out, const Complex& complex)
    {
        out << complex.real;
        if (complex.imaginary >= 0)
        {
            out << " + " << complex.imaginary << "i";
        }
        else
        {
            out << " - " << -complex.imaginary << "i";
        }
        return out;
    }
};

int main()
{
    setlocale(LC_ALL, "ru");
    try
    {
        Complex c1(2.0, 3.0);
        Complex c2(1.0, -2.0);

        cout << "c1: " << c1 << endl;
        cout << "c2: " << c2 << endl;
        cout << "Подсчёт..." << endl;
        Sleep(2000);
        Complex sum = c1 + c2;
        cout << "c1 + c2: " << sum << endl;

        Complex difference = c1 - c2;
        cout << "c1 - c2: " << difference << endl;

        Complex product = c1 * c2;
        cout << "c1 * c2: " << product << endl;

        Complex quotient = c1 / c2;
        cout << "c1 / c2: " << quotient << endl;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
    }
    return 0;
}
