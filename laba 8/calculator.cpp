#include "calculator.h"
#include <string>
using namespace std;
calculator::calculator() = default;
calculator::calculator(string expression) {
    for (int i = 0; i < expression.length(); ++i) {
        if (IsValue(expression[i])){
            string ForExpression;
            while (IsValue(expression[i]) || IsPoint(expression[i])) {
                ForExpression += expression[i];
                i++;
            }
            StackOfValues << stod(ForExpression);
        }
        if (IsOperator(expression[i])) {
            if(StackOfOperators.IsEmpty()) {
                StackOfOperators << expression[i];
                continue;
            } else {
                if (OperationPriority(expression[i]) > OperationPriority(StackOfOperators.GetTop()) || expression[i]=='(') {
                    StackOfOperators << expression[i];
                } else {
                    while (OperationPriority(expression[i]) <= OperationPriority(StackOfOperators.GetTop())) {
                        if (expression[i] == ')' && StackOfOperators.GetTop() == '(') {
                            StackOfOperators.pop();
                            break;
                        }
                        double SecondValue = StackOfValues.pop();
                        double FirstValue = StackOfValues.pop();
                        StackOfValues << IntermediateResult(FirstValue, SecondValue, StackOfOperators.pop());
                    }
                    if (expression[i] != ')'){
                        StackOfOperators << expression[i];
                    }
                }
            }
        }
        if (IsDelimiter(expression[i])) {
            continue;
        }
    }
}
double calculator::calculate() {
    while (!StackOfOperators.IsEmpty()) {
        double SecondValue = StackOfValues.pop();
        double FirstValue  = StackOfValues.pop();
        StackOfValues << IntermediateResult(FirstValue, SecondValue, StackOfOperators.pop());
    }
    return StackOfValues.pop();
}
