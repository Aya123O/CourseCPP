#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex(double r = 0, double i = 0) {
        real = r;
        imaginary = i;
    }

   /* ~Complex() {
        cout << "Complex number (" << real << " + " << imaginary << "i) is being destroyed" << endl;
    }
    */

    double getReal() { return real; }
    double getImaginary() { return imaginary; }
    void setReal(double r) { real = r; }
    void setImaginary(double i) { imaginary = i; }
    void setComplex(double r, double i) {
        real = r;
        imaginary = i;
    }

    Complex operator+(Complex& c) {
        return Complex(real + c.real, imaginary + c.imaginary);
    }

    Complex operator-(Complex& c) {
        return Complex(real - c.real, imaginary - c.imaginary);
    }

    Complex operator+(int x) {
        return Complex(real + x, imaginary + x);
    }

    Complex operator-(int x) {
        return Complex(real - x, imaginary - x);
    }

    friend Complex operator+(int x, Complex& c) {
        return Complex(c.real + x, c.imaginary + x);
    }

    friend Complex operator-(int x, Complex& c) {
        return Complex(x - c.real, x - c.imaginary);
    }

    Complex& operator++() {
        ++real;
        ++imaginary;
        return *this;
    }

    Complex operator++(int) {
        Complex temp = *this;
        ++(*this);
        return temp;
    }

    Complex& operator--() {
        --real;
        --imaginary;
        return *this;
    }

    Complex operator--(int) {
        Complex temp = *this;
        --(*this);
        return temp;
    }

    void display() {
        if (real == 0 && imaginary == 0) {
            cout << "0" << endl;
        } else if (real == 0) {
            cout << imaginary << "i" << endl;
        } else if (imaginary == 0) {
            cout << real << endl;
        } else {
            if (imaginary < 0)
                cout << real << " - " << -imaginary << "i" << endl;
            else
                cout << real << " + " << imaginary << "i" << endl;
        }
    }
};

int main() {
    Complex c1(10, 3);
    Complex c2(5, 2);
    Complex c3;

    c3 = c1 + c2;
    cout << "The sum (Complex + Complex) is: ";
    c3.display();

    c3 = c1 - c2;
    cout << "The difference (Complex - Complex) is: ";
    c3.display();

    c3 = c1 + 5;
    cout << "The sum (Complex + int) is: ";
    c3.display();

    c3 = c1 - 5;
    cout << "The difference (Complex - int) is: ";
    c3.display();

    c3 = 5 + c1;
    cout << "The sum (int + Complex) is: ";
    c3.display();

    c3 = 5 - c1;
    cout << "The difference (int - Complex) is: ";
    c3.display();

    cout << "Original c1: ";
    c1.display();
    cout << "After pre-increment (++c1): ";
    ++c1;
    c1.display();

    cout << "After post-increment (c1++): ";
    c1++;
    c1.display();

    cout << "After pre-decrement (--c1): ";
    --c1;
    c1.display();

    cout << "After post-decrement (c1--): ";
    c1--;
    c1.display();

    return 0;
}
