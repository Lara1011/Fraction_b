//
// Created by Lara Abu Hamad on 15/04/2023.
//

#ifndef CPP_HW3_FRACTION_H
#define CPP_HW3_FRACTION_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

namespace ariel {
    class Fraction {
    private:
        int numerator;
        int denominator;
        const int __gcd(int first, int second);
        void reduce();
    public:
        Fraction();
        explicit Fraction(int numerator);
        explicit Fraction(double number);
        Fraction(int numerator, int denominator);

        int getNumerator();
        void setNumerator(int numer);
        int getDenominator();
        void setDenominator(int denom);

        friend Fraction operator+(const Fraction& left,const Fraction& right);
        friend Fraction operator-(const Fraction& left,const Fraction& right);
        friend Fraction operator*(const Fraction& left,const Fraction& right);
        friend Fraction operator/(const Fraction& left,const Fraction& right);


        friend Fraction operator+(const Fraction& left, const Fraction& right);
        friend Fraction operator-(const Fraction& left, const Fraction& right);
        friend Fraction operator*(const Fraction& left, const Fraction& right);
        friend Fraction operator/(const Fraction& left, const Fraction& right);

        friend Fraction operator+(const double& num, const Fraction& frac);
        friend Fraction operator-(const double& num, const Fraction& frac);
        friend Fraction operator*(const double& num, const Fraction& frac);
        friend Fraction operator/(const double& num, const Fraction& frac);

        friend Fraction operator+(const int& num, const Fraction& frac);
        friend Fraction operator-(const int& num, const Fraction& frac);
        friend Fraction operator*(const int& num, const Fraction& frac);
        friend Fraction operator/(const int& num, const Fraction& frac);

        friend Fraction operator+(const Fraction& frac, const double& num);
        friend Fraction operator-(const Fraction& frac, const double& num);
        friend Fraction operator*(const Fraction& frac, const double& num);
        friend Fraction operator/(const Fraction& frac, const double& num);

        friend Fraction operator+(const Fraction& frac, const int& num);
        friend Fraction operator-(const Fraction& frac, const int& num);
        friend Fraction operator*(const Fraction& frac, const int& num);
        friend Fraction operator/(const Fraction& frac, const int& num);



        friend bool operator>(const double& num, const Fraction& frac);
        friend bool operator<(const double& num, const Fraction& frac);
        friend bool operator==(const double& num, const Fraction& frac);
        friend bool operator!=(const double& num, const Fraction& frac);
        friend bool operator>=(const double& num, const Fraction& frac);
        friend bool operator<=(const double& num, const Fraction& frac);

        friend bool operator>(const int& num, const Fraction& frac);
        friend bool operator<(const int& num, const Fraction& frac);
        friend bool operator==(const int& num, const Fraction& frac);
        friend bool operator!=(const int& num, const Fraction& frac);
        friend bool operator>=(const int& num, const Fraction& frac);
        friend bool operator<=(const int& num, const Fraction& frac);

        friend bool operator>(const Fraction& frac, const double& num);
        friend bool operator<(const Fraction& frac, const double& num);
        friend bool operator==(const Fraction& frac, const double& num);
        friend bool operator!=(const Fraction& frac, const double& num);
        friend bool operator>=(const Fraction& frac, const double& num);
        friend bool operator<=(const Fraction& frac, const double& num);

        friend bool operator>(const Fraction& frac, const int& num);
        friend bool operator<(const Fraction& frac, const int& num);
        friend bool operator==(const Fraction& frac, const int& num);
        friend bool operator!=(const Fraction& frac, const int& num);
        friend bool operator>=(const Fraction& frac, const int& num);
        friend bool operator<=(const Fraction& frac, const int& num);

        friend bool operator>(const Fraction& left, const Fraction& right);
        friend bool operator<(const Fraction& left, const Fraction& right);
        friend bool operator==(const Fraction& left, const Fraction& right);
        friend bool operator!=(const Fraction& left, const Fraction& right);
        friend bool operator>=(const Fraction& left, const Fraction& right);
        friend bool operator<=(const Fraction& left, const Fraction& right);


        Fraction operator++();
        const Fraction operator++(int);
        Fraction operator--();
        const Fraction operator--(int);

        friend ostream& operator<<(ostream& out, const Fraction& frac);
        friend istream& operator>>(istream& ins, Fraction& frac);

        explicit operator double() const;
        explicit operator string() const;
    };
}

#endif //CPP_HW3_FRACTION_H
