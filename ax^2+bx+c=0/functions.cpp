#include <iostream>
#include<math.h>
#include "functions.h"
using namespace std;
int discriminant(int a, int b, int c) {
	int value_of_discriminant = b * b - 4 * a * c;
	return value_of_discriminant;
}
double root_with_plus(int a, int b, int c) {
	double root_with_plus = (double)(-b + sqrt(discriminant(a, b, c))) / (2 * a);
	return root_with_plus;
}
double root_with_minus(int a, int b, int c) {
	double root_with_minus = (double)(-b - sqrt(discriminant(a, b, c))) / (2 * a);
	return root_with_minus;
}
int desision(int a, int b, int c) {
	if (a == 0) {
		if (b == 0) {
			if (c == 0) {
				cout << "The root of the equation is all numbers" << endl;
				return 1;
			}
			else {
				cout << "The equation has no real roots" << endl;
				return 4;
			}
		}
		else {
			if (c == 0) {
				cout << "The root of the equation is 0" << endl;
				return 3;
			}
			else {
				cout << "The root of the equation is " << (-c) / b << endl;
				return 6;
			}
		}
	}
	else {
		if (b == 0) {
			if (c == 0) {
				cout << "The root of the equation is 0" << endl;
				return 2;
			}
			else {
				if (discriminant(a, b, c) > 0) {
					cout << "The root of the equation are " << root_with_minus(a, b, c) << " and " << root_with_plus(a, b, c) << endl;
					return 7;
				}
				else if (discriminant(a, b, c) == 0) {
					cout << "The root of the equation is " << (-b) / (2 * a) << endl;
					return 9;
				}
				else {
					cout << "The equation has no real roots" << endl;
					return 10;
				}
			}
		}
		else {
			if (discriminant(a, b, c) > 0) {
				if (c == 0) {
				double result, O = 0;
				result = (double)(-b / a);
				cout << "The root of the equation are " << min(O, result) << " and " << max(O, result) << endl;
				return 5;
				}
				else {
				cout << "The roots of the equation are " << root_with_minus(a, b, c) << " and " << root_with_plus(a, b, c) << endl;
				return 8;
				}
			}
			else if (discriminant(a, b, c) == 0) {
				cout << "The root of the equation is " << (-b) / (2 * a) << endl;
				return 9;
			}
			else {
				cout << "The equation has no real roots" << endl;
				return 10;
			}	
		}
	}
}
