#include <iostream>
#include "functions.h"
#include "test.h"
using namespace std;
int main(){
	int a, b, c;
	cout << "Enter a, b, c for equation of the form" << endl;
	cout << "a = ";
	cin >> a;
	cout << endl << "b = ";
	cin >> b;
	cout << endl << "c = ";
	cin >> c;
	desision(a, b, c);
	run_tests();
	return 0;
}