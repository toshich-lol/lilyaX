#pragma once
#include<iostream>

using namespace std;

class proper_fraction {
public:
    proper_fraction(int num, int denom);
    proper_fraction(const proper_fraction& copy);
    int get_fraction_numenator();
    int get_fraction_denominator();
    void print();
    void cut_fraction();
    void fraction_sum(int term);
    void fraction_sum(proper_fraction term);
    void fraction_multiplication(int factor);
    void fraction_multiplication(proper_fraction factor);
    void fraction_division(int divider);
    void fraction_division(proper_fraction divider);
private:
    static int number(int a);
    static int sign(int a);
    int numerator;
    int denominator;
};