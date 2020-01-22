// COPYRIGHT (C) 2019 Danielle Reed (djr98) All rights reserved.
//
// rational.h: Contains prototypes of functions for the rational calculator. Definitions found in RATIONAL.cpp

#ifndef RATIONAL_H
#define RATIONAL_H

#include <cstdlib>
#include <iosfwd>
#include <iostream>
#include <stdlib.h>

using std::cout;
using std::endl;
using std::cin;

//function that finds the greatest common factor between two integers.
//precondition: accepts two integers
//postcondition: returns one integer that holds the greatest common factor between the given integers
int gcd(int, int);

//function that finds the least common multiple between two integers.
//precondition: accepts two integers.
//postcondition: returns an integer holding the least common multiple
int lcm(int, int);

//a simplify function.
//precondition: accepts two integers
//postcondition: changes the two integers into simpler version if possible by using their GCD
void simplify(int&, int&);

// Represents a rational number. The rational numbers are the set of
// numbers that can be represented as the quotient of two integers.
// the definition can be a struct or a class
class Rational
{
private:

    int numerator;
    int denominator;

public:

    //A default constructor
    Rational();

    //A constructor that takes an integer value
    Rational(int value);

    //A constructor that takes a pair of values
    Rational(int, int);



    //overloading of == between Rationals
    //precondition:accepts a valid rational class
    //postcondition:returns a boolean if the rational on the right is the same as the one on the left
    bool operator==(Rational);

    //overloading of = between Rationals
    //precondition:accepts a valid rational class
    //postcondition:returns a boolean if the rational on the right is not equal to the one on the left
    bool operator!=(Rational&);

    //overloading of < between Rationals
    //precondition:accepts a valid rational class
    //postcondition:returns a boolean if the rational on the right is greater than the one on the left
    bool operator<(Rational&);

    //overloading of > between Rationals
    //precondition:accepts a valid rational class
    //postcondition:returns a boolean if the rational on the right is less than the one on the left
    bool operator>(Rational&);

    //Overloading of <= between Rationals
    //precondition:accepts a valid rational class
    //postcondition:returns a boolean if the rational on the right is greater than or equal to the one on the left
    bool operator<=(Rational&);

    //overloading of >= between Rationals
    //precondition:accepts a valid rational class
    //postcondition:return a boolean if the rational on the right is less than or equal to the one on the left
    bool operator>=(Rational&);

    //overloading of + between Rationals
    //precondition:accepts a valid rational class
    //postcondition:returns a rational that holds the value of the class on the left and the right added
    Rational operator+(Rational&);

    //overloading of - between Rationals
    //precondition:accepts a valid rational class
    //postcondition:returns a rational that holds the value of the class on the left and the right subtracted
    Rational operator-(Rational&);

    //overloading of * between Rationals
    //precondition:accepts a valid rational class
    //postcondition:returns a rational that holds the value of the class on the left and the right multiplied
    Rational operator*(Rational&);

    //overloading of / between Rationals
    //precondition:accepts a valid rational class
    //postcondition:returns a rational that holds the value of the class one the left and the right divided
    Rational operator/(Rational&);

    // inline these b/c they are short
    // Returns the numerator.
    int num() const { return numerator; }

    // Returns the denominator
    int den() const { return denominator; }

    //set the numerator
    //precondition:accepts an integer
    //postcondition:adjusts the numerator in the class to the int
    void getNum(int);

    //set the denominator
    //precondition:accepts an integer
    //postcondition:adjusts the denominator in the class to the int
    void getDen(int);

    //overloading of == between a rational and a integer
    //precondition: accepts an integer and a valid Rational class
    //postcondition:returns a boolean true if the int and rational are equivalent, false otherwise
    friend bool operator==(int, Rational&);
    friend bool operator==(Rational&, int);

    //overloading of != between a rational and a integer
    //precondition:accepts an integer and a valid Rational class
    //postcondition:returns a boolean true if the int and rational are not equivalent, false otherwise
    friend bool operator!=(int, Rational&);
    friend bool operator!=(Rational&, int);

    //overloading of < between a rational and a integer
    //precondition:accepts an integer and a valid Rational class
    //postcondition:returns a boolean true if the int is smaller than the rational and false otherwise
    friend bool operator<(int, Rational&);
    friend bool operator<(Rational&, int);

    //overloading of > between a rational and a integer
    //precondition:accepts an integer and a valid Rational class
    //postcondition:returns a boolean true if the int is larger than the rational and false otherwise
    friend bool operator>(int, Rational&);
    friend bool operator>(Rational&, int);

    //overloading of <= between a rational and a integer
    //precondition:accepts an integer and a valid Rational class
    //postcondition:returns a boolean true if the int is smaller than the rational or if equivalent and false otherwise
    friend bool operator<=(int, Rational&);
    friend bool operator<=(Rational&, int);

    //overloading of >= between a rational and a integer
    //precondition:accepts an integer and a valid Rational class
    //postcondition:returns a boolean true if the int is larger than the rational or if equivalent and false otherwise
    friend bool operator>=(int, Rational&);
    friend bool operator>=(Rational&, int);

    //overloading of + between a rational and a integer
    //precondition:accepts an integer and a valid Rational class
    //postcondition:returns an int containing the addition between an int and a rational
    friend int operator+(int, Rational&);
    friend int operator+(Rational&, int);

    //overloading of - between a rational and a integer
    //precondition:accepts an integer and a valid Rational class
    //postcondition:returns an int containing the subtraction between an int and a rational
    friend int operator-(int, Rational&);
    friend int operator-(Rational&, int);

    //overloading of * between a rational and a integer
    //precondition:accepts an integer and a valid Rational class
    //postcondition:returns an int containing the multiplication between an int and a rational
    friend int operator*(int, Rational&);
    friend int operator*(Rational&, int);

    //overloading of / between a rational and a integer
    //precondition:accepts an integer and a valid Rational class
    //postcondition:returns an int containing the division between an int and a rational
    friend int operator/(int, Rational&);
    friend int operator/(Rational&, int);

};



std::ostream& operator<<(std::ostream&, Rational);
std::istream& operator>>(std::istream&, Rational&);

#endif
