#include <iostream>
#include "strkitten.h"
#include "Test.h"
using namespace std;
int main() {
    cout << "Enter first string" << endl;
    char* strone = new char[600];
    cin.getline(strone, 600);
    cout << "Enter second string" << endl;
    char* strtwo = new char[300];
    cin.getline(strtwo, 300);
    strkitten(strone, strtwo);
    cout << "Your kitten-string:\n" << strone << endl;
    run_tests();
    delete[] strone;
    delete[] strtwo;
    return 0;
}