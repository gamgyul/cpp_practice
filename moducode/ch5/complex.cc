#include "common.h"
class Complex {
private:
    double real_;
    double img_;
    
public:
    Complex(double real, double img) : real_(real), img_(img) {}
    Complex operator+(const Complex &c2) const;
    Complex operator-(const Complex &c2) const;
    Complex operator*(const Complex &c2) const;
    Complex operator/(const Complex &c2) const;
    Complex &operator=(const Complex &c2);
    Complex &operator+=(const Complex &c2);
    Complex &operator-=(const Complex &c2);
    Complex &operator*=(const Complex &c2);
    Complex &operator/=(const Complex &c2);
    
    friend std::ostream &operator<<(std::ostream &os, const Complex &c2);
    
    void println() { std::cout << "( " << real_ <<", " << img_ << " )" << std::endl;}
};

Complex& Complex::operator=(const Complex &c2) {
    real_ = c2.real_;
    img_ = c2.img_;
    return *this;
}

Complex Complex::operator+(const Complex &c2) const {
    Complex tmp(real_ + c2.real_, img_ + c2.img_);
    return tmp;
}

Complex Complex::operator-(const Complex &c2) const {
    Complex tmp(real_ - c2.real_, img_ - c2.img_);
    return tmp;
}

Complex Complex::operator*(const Complex &c2) const {
    Complex tmp(real_ * c2.real_ - img_ * c2.img_,
                real_ * c2.img_ + img_ * c2.real_);
    return tmp;
}

Complex Complex::operator/(const Complex &c2) const {
    Complex tmp(
    (real_ * c2.real_ +  img_ * c2.img_) / (real_ * real_ + c2.real_ * c2.real_),
    (c2.real_ * img_ -  real_ * c2.img_) / (real_ * real_ + c2.real_ * c2.real_)
    );
    return tmp;
}
Complex& Complex::operator+=(const Complex &c2) {
    *this = *this + c2;
    return *this;
}

Complex& Complex::operator-=(const Complex &c2) {
    *this = *this - c2;
    return *this;
}

Complex& Complex::operator*=(const Complex &c2) {
    *this = *this * c2;
    return *this;
}

Complex& Complex::operator/=(const Complex &c2) {
    *this = *this / c2;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Complex &c2) {
     os << "( " << c2.real_ <<", " << c2.img_ << " )" << std::endl;
     return os;
}
int main() {
    Complex a(1.0, 2.0);
    Complex b(3.0, -2.0);

    Complex c = a * b;
    c.println();
    Complex d(1.0, 1.0);
    d += a;
    std::cout << "d : " << d << std::endl;
    return 0;
}