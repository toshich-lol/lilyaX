#include "functions.h"
#include <cmath>
bool IsOperator(char symbol) {
    if (symbol == '(' || symbol == '-' || symbol =='+' || symbol == ')' || symbol == '*' || symbol == '/' || symbol == '^'){
        return true;
    }
    return false;
}
bool IsValue(char symbol) {
    if (symbol == '0' || symbol == '1' || symbol == '2' || symbol == '3' || symbol == '4' || symbol == '5' || symbol == '6' || symbol == '7' || symbol == '8' || symbol == '9'){
        return true;
    }
    return false;
}
bool IsDelimiter(char symbol){
    if (symbol == ' ' || symbol == '\n' || symbol =='\t'){
        return true;
    }
    return false;
}
bool IsPoint(char symbol){
    if (symbol == '.'){
        return true;
    }
    return false;
}
bool IsNormal(char symbol){
    if(IsPoint(symbol)|| IsValue(symbol) || IsDelimiter(symbol) || IsOperator(symbol)){
        return true;
    }
    return false;
}
double IntermediateResult(double first, double second, char operation){
        if(operation == '+') {return first + second;}
        else if(operation == '-') {return first - second;}
        else if(operation == '*') {return first * second;}
        else if(operation == '/') {
            if(second == 0) {
                throw "Cant' divide on 0";
            }
            return first / second;
        }
        else if(operation == '^') {
            if (second == 0 && first == 0){
                throw "Cant' 0^0";
            }
            return pow(first,second);
        }
    return 0;
}
int OperationPriority(char operation){
    if(operation == ')') {return 1;}
    else if(operation == '(') {return 1;}
    else if(operation == '+' || operation == '-') {return 2;}
    else if(operation == '*' || operation == '/') {return 3;}
    else if(operation == '^') {return 4;}
    return -1;
}
void Transformer(std::string &expression){
    if(expression[0] == '-' || expression[0] == '+') {
        expression.insert(0, "0" );
    }
    for (int i = 0; i < expression.length(); ++i) {
        if (expression[i] == '+' && expression[i+1] == '-'){
            expression.erase(i, 1);
        }//2+-2=2-2
        if (IsValue(expression[i]) && expression[i+1] == '('){
            expression.insert(i+1, "*");
        }//2(=2*(
        if (expression[i] == '-' && expression[i+1] == '-'){
            expression.erase(i, 1);
            expression.replace(i, 1, "+");
        }//2--2=2+2
        if(IsDelimiter(expression[i])){
            expression.erase(i,1);
        }
    }
    for (int i = 0; i < expression.length()-1; i++) {
        if (IsOperator(expression[i]) && expression[i] !=')' && expression[i + 1] == '-' && IsValue(expression[i + 2])) {
            expression.insert(i + 2, "1)*");
            expression.insert(i + 1,"(0");
        }
        if(expression[i] == ')' && expression[i] == ')') {
            expression.insert(i+1, "*");
        }
    }

}
int Check(std::string tested){
    int Count=0;
    for (int i = 0; i <tested.length(); i++) {
        if (!IsNormal(tested[i])) {
            return 1;

        }
        if (tested[i] == '(') {--Count;}
        if (tested[i] == ')') {++Count;}
    }
    if (Count != 0) {
        return 2;

    }
    if (IsOperator(tested[tested.size() - 1]) && tested[tested.size() - 1] !=')'){
     return 3;

    }
    if (!IsValue(tested[tested.size()-1])){
        for (int i = tested.size() - 2; i > 0 ; i--) {
            if (IsValue(tested[i]) && IsOperator(tested[i + 1]) && tested[i + 1] !=')') {
                 return 4;

            }
            if (IsValue(tested[i])){break;}
        }
    }
    for (int i = 1; i < tested.size() - 1; ++i) {
        if(tested[i - 1] != ')' && tested[i] != ')' && tested[i + 1] != ')' && tested[i - 1] != '(' &&
        tested[i] != '(' && tested[i + 1] != '(' && IsOperator(tested[i - 1]) && IsOperator(tested[i]) && IsOperator(tested[i + 1])){
            return 5;
        }
    }
    return 0;
}