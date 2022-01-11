#include <iostream>
#include "stack.h"
#include "calculator.h"
using namespace std;
int main() {
    string expression;
    getline(cin, expression);
    if(Check(expression)){
        cout << "Incorrect expression\n";
        throw "Incorrect expression";
    }
    Transformer(expression);
    calculator ex(expression);
    cout<<"\n\n>>>> " << ex.calculate() <<" <<<<"<< endl ;
    return 0;
}