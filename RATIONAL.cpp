// COPYRIGHT (C) 2019 Danielle Reed (djr98) All rights reserved.
//
// rational.h: Definitions of rational class and its interface. Prototypes found in RATIONAL.h

#include "rational.h"
#include <iostream>

// Compute the GCD of two integer values using Euclid's algorithm.
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }

    return gcd(b, a % b);
}

// Compute the LCM of two integer values.
int lcm(int a, int b)
{
    return (a*b)/gcd(a, b);
}

//outputs the variables in Rational
//if denominator == 1 then outputs just the numerator
std::ostream& operator<<(std::ostream &os, Rational r)
{
    if(r.den() == 1)
    {
        return os << r.num();
    }
    else
    {
        return os << r.num() << '/' << r.den();
    }

}

// TODO: Make this read integer values if no '/' is given as a separator.
// You may assume that there is no space between the numerator and the
// slash. Hint, find and read the reference documentation for istream::peek().
std::istream& operator>>(std::istream &is, Rational &r)
{
    int p, q;
    char c;

    while(is.peek() != EOF)
    {
        is >> p;

        if(is.peek() == ' ' || is.peek() == '\n' || is.peek() == '\t')
        {
            r = Rational(p, 1);
            return is;
        }
        else if(is.peek() == '/')
        {
            is >> c;
            is >> q;

            simplify(p, q);
            r = Rational(p, q);
            return is;
        }

        is >> c;
        is >> q;

        if(is.peek() == ' ' || is.peek() == '\n' || is.peek() == '\t')
        {
            r = Rational(p , 1);
            is >> c;
            is >> q;
        }
        else if(is.peek() == '/')
        {

        }

        if (!is)
        {
            return is;
        }
    }

    return is;
}

//default constructor
Rational::Rational()
{
    numerator = 0;
    denominator = 1;
}

//constructor with one integer
Rational::Rational(int value)
{
    numerator = value;
    denominator = 1;
}

//constructor with two integers
Rational::Rational(int value1, int value2)
{
    if(value2 == 0)
    {
        cout << "The denominator cannot be zero. Setting to 1 as default." << endl;
        denominator = 1;
    }

    simplify(value1, value2);
    numerator = value1;
    denominator = value2;
}

//adjusts numerator in class to given integer
void Rational::getNum(int newNum)
{
    numerator = newNum;
}

//adjusts denominator in class to given integer
void Rational::getDen(int newDen)
{
    denominator = newDen;
}

//simplifies the numerator and denominator by using the GCM
void simplify(int& numerator, int& denominator)
{
    int greatestDenominator = gcd(numerator, denominator);

    if(greatestDenominator != 0)
    {
        numerator = numerator / greatestDenominator;
        denominator = denominator / greatestDenominator;
    }
}

//overloaded == operator for Rationals
bool Rational::operator==(Rational right)
{
    return (right.num() == numerator && right.den() == denominator);
}

//overloaded != operator for Rationals
bool Rational::operator!=(Rational& right)
{
    return (right.num() != numerator || right.den() != denominator);
}

//overloaded < operator for Rationals
bool Rational::operator<(Rational& right)
{
    return (((numerator * right.den()) - (denominator * right.num())) < 0);
}

//overloaded > operator for Rationals
bool Rational::operator>(Rational& right)
{
    return (((numerator * right.den()) - (denominator * right.num())) > 0);
}

//overloaded <= operator for Rationals
bool Rational::operator<=(Rational& right)
{
    return ((right.num() == numerator && right.den() == denominator) || ((numerator * right.den()) - (denominator * right.num())) < 0);
}

//overloaded >= operator for Rationals
bool Rational::operator>=(Rational& right)
{
    return((right.num() == numerator && right.den() == denominator) || ((numerator * right.den()) - (denominator * right.num())) > 0);
}

//overloaded + operator for Rationals
Rational Rational::operator+(Rational& right)
{
    int tempDen = (right.den() * denominator);
    int tempRightNum = (denominator * right.num());
    int tempLeftNum = (right.den() * numerator);

    int finalResultNum = tempRightNum + tempLeftNum;

    simplify(finalResultNum, tempDen);

    Rational d(finalResultNum, tempDen);

    return d;
}

//overloaded - operator for Rationals
Rational Rational::operator-(Rational& right)
{
    int tempDen = (right.den() * denominator);
    int tempRightNum = (denominator * right.num());
    int tempLeftNum = (right.den() * numerator);

    int finalResultNum = tempLeftNum - tempRightNum;

    simplify(finalResultNum, tempDen);

    Rational d(finalResultNum, tempDen);
    return d;
}

//overloaded * operator for Rationals
Rational Rational::operator*(Rational& right)
{
    Rational d((right.num() * numerator), (right.den() * denominator));
    return d;
}

//overloaded / operator for Rationals
Rational Rational::operator/(Rational& right)
{
    int tempNum = right.den();
    int tempDen = right.num();

    int finalNum = tempNum * numerator;
    int finalDen = tempDen * denominator;

    simplify(finalNum, finalDen);

    Rational d(finalNum, finalDen);
    return d;
}

//overloaded == operator for an int first then rational
bool operator==(int right, Rational& left)
{
    return (left.den() != 1 || right != left.num());
}

//overloaded == operator for a rational first then int
bool operator==(Rational& right, int left)
{
    return (right.den() != 1 || left != right.num());
}

//overloaded != operator for an int first then rational
bool operator!=(int right,Rational& left)
{
    return (left.den() != 1 || right != left.num());
}

//overloaded != operator for a rational first then an int
bool operator!=(Rational& right, int left)
{
    return (right.den() != 1 || left != right.num());
}

//overloaded < operator for an int first then rational
bool operator<(int right, Rational& left)
{
    return (left.num() - (right * left.den()) < 0);
}

//overloaded < operator for a rational first then an int
bool operator<(Rational& right, int left)
{
    return (((left * right.den()) - right.num()) < 0);
}

//overloaded > operator for an int first then rational
bool operator>(int right, Rational& left)
{
    return (left.num() - (right * left.den()) > 0);
}

//overloaded > operator for a rational first then an int
bool operator>(Rational& right, int left)
{
    return(((left * right.den()) - right.num()) > 0);
}

//overloaded <= operator for an int first then rational
bool operator<=(int right, Rational& left)
{
    return ((left.num() - (right * left.den()) < 0) || (left.den() == 1 && right == left.num()));
}

//overloaded <= operator for a rational first then an int
bool operator<=(Rational& right, int left)
{
    return ((((left * right.den()) - right.num()) < 0) || (right.den() == 1 && left == right.num()));
}

//overloaded >= operator for an int first then rational
bool operator>=(int right, Rational& left)
{
    return ((left.num() - (right * left.den()) > 0) || (left.den() == 1 && right == left.num()));
}

//overloaded >= operator for a rational first then an int
bool operator>=(Rational& right, int left)
{
    return ((((left * right.den()) - right.num()) > 0) || (right.den() == 1 && left == right.num()));
}

//overloaded + operator for an int first then rational
int operator+(int right, Rational& left)
{
    return (((right * left.den()) + left.num()) / left.den());
}

//overloaded + operator for a rational first then an int
int operator+(Rational& right, int left)
{
    return (((left * right.den()) + right.num()) / right.den());
}

//overloaded - operator for an int first then rational
int operator-(int right, Rational& left)
{
    return ((left.num() - (right * left.den())) / left.den());
}

//overloaded - operator for a rational first then an int
int operator-(Rational& right, int left)
{
    return (((left * right.den()) - right.num()) / right.den());
}

//overloaded * operator for an int first then rational
int operator*(int right, Rational& left)
{
    return ((left.num() * right) / left.den());
}

//overloaded * operator for a rational first then an int
int operator*(Rational& right, int left)
{
    return ((right.num() * left) / right.den());
}

//overloaded / operator for an int first then rational
int operator/(int right, Rational& left)
{
    return ((left.den() * right) / left.num());
}

//overloaded / operator for a rational first then an int
int operator/(Rational& right, int left)
{
    return ((right.den() * left) / right.num());
}
