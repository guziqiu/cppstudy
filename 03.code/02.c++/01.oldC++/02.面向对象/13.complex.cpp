#include <iostream>

using namespace std;

class Complex
{
public:
    Complex(double, double);
    Complex operator+(const Complex&) const;
    Complex &operator+=(const Complex &);

    Complex operator-(const Complex&) const;
    Complex &operator-=(const Complex &);

    Complex operator*(const Complex&) const;
    Complex &operator*=(const Complex &);

    Complex operator/(const Complex&) const;
    Complex &operator/=(const Complex &);

    friend ostream &operator<<(ostream&, const Complex&);

private:
    double real, imagin;
};

Complex::Complex(double real, double imagin):real(real), imagin(imagin){}

Complex Complex::operator+(const Complex &add) const {
    return Complex(this->real + add.real, this->imagin + add.imagin);
}

Complex Complex::operator-(const Complex &sub) const {
    return Complex(this->real - sub.real, this->imagin - sub.imagin);
}

Complex Complex::operator*(const Complex &mul) const {
    return Complex(this->real * mul.real - this->imagin * mul.imagin, this->imagin * mul.real + this->real * mul.imagin);
}

Complex Complex::operator/(const Complex &div) const {
    if (div.real == 0 && div.imagin == 0) {
        cout << "can not calc" << endl;
        return Complex(0, 0);
    }
    double tmp = div.real * div.real + div.imagin * div.imagin;
    return Complex((this->real * div.real + this->imagin * div.imagin) / tmp, (this->imagin * div.real - this->real * div.imagin) / tmp);
}

ostream &operator<<(ostream &out, const Complex &c) {
    out << c.real << " + " << c.imagin << "i";
    return out;
}

int main() {
    double a1, b1, a2, b2;
    cin >> a1 >> b1 >> a2 >> b2;
    Complex c1(a1, b1);
    Complex c2(a2, b2);
    cout << "(" << c1 << ") + (" << c2 << ") = " << c1 + c2 << endl;
    cout << "(" << c1 << ") - (" << c2 << ") = " << c1 - c2 << endl;
    cout << "(" << c1 << ") * (" << c2 << ") = " << c1 * c2 << endl;
    cout << "(" << c1 << ") / (" << c2 << ") = " << c1 / c2 << endl;
    return 0;
}