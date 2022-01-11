#pragma once
#include <string>
#include "stack.h"
#include "functions.h"
using namespace std;
class calculator {
private:
    calculator();
    Stack<double> StackOfValues;
    Stack<char> StackOfOperators;
public:
    calculator(string expression);
    double calculate();
};
