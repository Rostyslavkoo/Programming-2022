#include <iostream>

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0.0, double i = 0.0) : real(r), imaginary(i) {}

    Complex operator+(const Complex& other) {
        Complex result;
        result.real = real + other.real;
        result.imaginary = imaginary + other.imaginary;
        return result;
    }

    void display() {
        std::cout << real << " + " << imaginary << "i" << std::endl;
    }
};

int main() {
    Complex c1(2.5, 3.5);
    Complex c2(1.2, 0.8);
    Complex c3 = c1 + c2;
    c3.display(); // Результат: 3.7 + 4.3i

    return 0;
}
