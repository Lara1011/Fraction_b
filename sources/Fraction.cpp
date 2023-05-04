//
// Created by Lara Abu Hamad on 15/04/2023.
//

#include "Fraction.hpp"
#include <cmath>
using namespace std;

namespace ariel {
    Fraction::Fraction() : numerator(0), denominator(1) {}

    Fraction::Fraction(int numerator) : numerator(numerator), denominator(1) {
        reduce();
    }

    Fraction::Fraction(double number) {
        denominator = pow(10, 3);
        numerator = round(number * denominator);
        reduce();
    }

    Fraction::Fraction(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
        if (denominator == 0)
            throw invalid_argument("Division by 0");
        if (denominator < 0) {
            numerator *= -1;
            denominator *= -1;
        }
        reduce();
    }

    const int Fraction::gcd(int first, int second) {
        return second == 0 ? first : gcd(second, first % second);
    }

    void Fraction::reduce() {
        int gcd = abs(Fraction::gcd(numerator, denominator));
        numerator /= gcd;
        denominator /= gcd;
    }

    int Fraction::getDenominator() {
        return this->denominator;
    }

    int Fraction::getNumerator() {
        return this->numerator;
    }

    void Fraction::setDenominator(int denom) {
        this->denominator = denom;
    }

    void Fraction::setNumerator(int numer) {
        this->numerator = numer;
    }

    Fraction operator+(const Fraction &left, const Fraction &right) {
        long long int numer = static_cast<long long int>(left.numerator) * right.denominator +
                            static_cast<long long int>(right.numerator) * left.denominator;
        long long int denom = static_cast<long long int>(left.denominator) * right.denominator;
        if (numer > std::numeric_limits<int>::max() || numer < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Number is too large !");
        }
        return {static_cast<int>(numer), static_cast<int>(denom)};
    }

    Fraction operator-(const Fraction &left, const Fraction &right) {
        long long int numer = static_cast<long long int>(left.numerator) * right.denominator - static_cast<int64_t>(right.numerator) * left.denominator;
        long long int denom = static_cast<long long int>(left.denominator) * right.denominator;
        if (numer > std::numeric_limits<int>::max() || numer < std::numeric_limits<int>::min() ||
                denom > std::numeric_limits<int>::max() || denom < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Number is too large !!");
        }
        return {static_cast<int>(numer), static_cast<int>(denom)};
    }

    Fraction operator*(const Fraction &left, const Fraction &right) {
        long long int numer = static_cast<long long int>(left.numerator) * right.numerator;
        long long int denom = static_cast<long long int>(left.denominator) * right.denominator;
        if (numer > std::numeric_limits<int>::max() || denom > std::numeric_limits<int>::max()) {
            throw std::overflow_error("Number is too large !");
        }
        return {static_cast<int>(numer), static_cast<int>(denom)};
    }

    Fraction operator/(const Fraction &left, const Fraction &right) {
        long long int numer = static_cast<long long int>(left.numerator) * right.denominator;
        long long int denom = static_cast<long long int>(left.denominator) * right.numerator;
        if(denom == 0)
            throw runtime_error("Division by zero!");
        if (numer > std::numeric_limits<int>::max() || numer < std::numeric_limits<int>::min() ||
                denom > std::numeric_limits<int>::max() || denom < std::numeric_limits<int>::min()) {
            throw std::overflow_error("Number is too large !!");
        }
        return {static_cast<int>(numer), static_cast<int>(denom)};
    }

    Fraction operator+(const double &num, const Fraction &frac) {
        Fraction f(num);
        return f + frac;
    }

    Fraction operator-(const double &num, const Fraction &frac) {
        Fraction f(num);
        return f - frac;
    }

    Fraction operator*(const double &num, const Fraction &frac) {
        Fraction f(num);
        return f * frac;
    }

    Fraction operator/(const double &num, const Fraction &frac) {
        Fraction f(num);
        return f / frac;
    }

    Fraction operator+(const int &num, const Fraction &frac) {
        Fraction f(num);
        return f + frac;
    }

    Fraction operator-(const int &num, const Fraction &frac) {
        Fraction f(num);
        return f - frac;
    }

    Fraction operator*(const int &num, const Fraction &frac) {
        Fraction f(num);
        return f * frac;
    }

    Fraction operator/(const int &num, const Fraction &frac) {
        Fraction f(num);
        return f / frac;
    }

    Fraction operator+(const Fraction &frac, const double &num) {
        Fraction f(num);
        return frac + f;
    }

    Fraction operator-(const Fraction &frac, const double &num) {
        Fraction f(num);
        return frac - f;
    }

    Fraction operator*(const Fraction &frac, const double &num) {
        Fraction f(num);
        return frac * f;
    }

    Fraction operator/(const Fraction &frac, const double &num) {
        Fraction f(num);
        return frac / f;
    }

    Fraction operator+(const Fraction &frac, const int &num) {
        Fraction f(num);
        return frac + f;
    }

    Fraction operator-(const Fraction &frac, const int &num) {
        Fraction f(num);
        return frac - f;
    }

    Fraction operator*(const Fraction &frac, const int &num) {
        Fraction f(num);
        return frac * f;
    }

    Fraction operator/(const Fraction &frac, const int &num) {
        Fraction f(num);
        return frac / f;
    }


    bool operator>(const Fraction &left, const Fraction &right) {
        return left.operator double() > right.operator double();
    }

    bool operator<(const Fraction &left, const Fraction &right) {
        return left.operator double() < right.operator double();
    }

    bool operator==(const Fraction &left, const Fraction &right) {
        return left.operator double() == right.operator double();
    }

    bool operator!=(const Fraction &left, const Fraction &right) {
        return left.operator double() != right.operator double();
    }

    bool operator>=(const Fraction &left, const Fraction &right) {
        return left.operator double() >= right.operator double();
    }

    bool operator<=(const Fraction &left, const Fraction &right) {
        return left.operator double() <= right.operator double();
    }

    bool operator>(const Fraction &frac, const double &num) {
        return frac.operator double() > num;
    }

    bool operator<(const Fraction &frac, const double &num) {
        return frac.operator double() < num;
    }

    bool operator==(const Fraction &frac, const double &num) {
        return frac.operator double() == num;
    }

    bool operator!=(const Fraction &frac, const double &num) {
        return frac.operator double() != num;
    }

    bool operator>=(const Fraction &frac, const double &num) {
        return frac.operator double() >= num;
    }

    bool operator<=(const Fraction &frac, const double &num) {
        return frac.operator double() <= num;
    }

    bool operator>(const Fraction &frac, const int &num) {
        return frac.operator double() > num;
    }

    bool operator<(const Fraction &frac, const int &num) {
        return frac.operator double() < num;
    }

    bool operator==(const Fraction &frac, const int &num) {
        return frac.operator double() == num;
    }

    bool operator!=(const Fraction &frac, const int &num) {
        return frac.operator double() != num;
    }

    bool operator>=(const Fraction &frac, const int &num) {
        return frac.operator double() >= num;
    }

    bool operator<=(const Fraction &frac, const int &num) {
        return frac.operator double() <= num;
    }

    bool operator>(const double &num, const Fraction &frac) {
        return num > frac.operator double();
    }

    bool operator<(const double &num, const Fraction &frac) {
        return num < frac.operator double();
    }

    bool operator==(const double &num, const Fraction &frac) {
        return num == frac.operator double();
    }

    bool operator!=(const double &num, const Fraction &frac) {
        return num != frac.operator double();
    }

    bool operator>=(const double &num, const Fraction &frac) {
        return num >= frac.operator double();
    }

    bool operator<=(const double &num, const Fraction &frac) {
        return num <= frac.operator double();
    }

    bool operator>(const int &num, const Fraction &frac) {
        return num > frac.operator double();
    }

    bool operator<(const int &num, const Fraction &frac) {
        return num < frac.operator double();
    }

    bool operator==(const int &num, const Fraction &frac) {
        return num == frac.operator double();
    }

    bool operator!=(const int &num, const Fraction &frac) {
        return num != frac.operator double();
    }

    bool operator>=(const int &num, const Fraction &frac) {
        return num >= frac.operator double();
    }

    bool operator<=(const int &num, const Fraction &frac) {
        return num <= frac.operator double();
    }

    Fraction Fraction::operator++() {
        numerator += denominator;
        reduce();
        return *this;
    }

    const Fraction Fraction::operator++(int) {
        Fraction temp = *this;
        numerator += denominator;
        reduce();
        return temp;
    }

    Fraction Fraction::operator--() {
        numerator -= denominator;
        reduce();
        return *this;
    }

    const Fraction Fraction::operator--(int) {
        Fraction temp = *this;
        numerator -= denominator;
        reduce();
        return temp;
    }

    ostream &operator<<(ostream &out, const Fraction &frac) {
        int numerator = frac.numerator;
        int denominator = frac.denominator;
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
        out << numerator << "/" << denominator;
        return out;
    }

    istream &operator>>(istream &ins, Fraction &frac) {
        int numerator, denominator;
        ins >> numerator >> denominator;
        if(ins.fail())
            throw runtime_error("Invalid input");
        if(denominator == 0)
            throw runtime_error("Division by zero!");
        if(denominator < 0){
            denominator *= -1;
            numerator *= -1;
        }
        frac = Fraction(numerator, denominator);
        return ins;
    }

    Fraction::operator double() const {
        return double(numerator) / double(denominator);
    }

    Fraction::operator string() const {
        return to_string(numerator) + "/" + to_string(denominator);
    }
}