#include "proper_fraction.h"
int proper_fraction::sign(int a) {
	if (a < 0) {
		return -1;
	}
	else if (a > 0) {
		return 1;
	}
	else if (a == 0) {
		return 0;
	}
}
int proper_fraction::number(int a) {
	int n = 1;
	while (a >= 10) {
		a /= 10;
		n++;
	}
	return n;
}
proper_fraction::proper_fraction(int num, int denom) {
	if (denom == 0) {
		cout << "denominator must be non-zero" << endl;
		exit(1);
	}
	else if (abs(num) > abs(denom)) {
		cout << "Numenator must be less than or equal to the denominator" << endl;
		exit(1);
	}
	else {
		numerator = num;
		denominator = denom;
		cut_fraction();
	}
}
proper_fraction::proper_fraction(const proper_fraction& copy) {
	this->numerator = copy.numerator;
	this->denominator = copy.denominator;
}
void proper_fraction::print() {
	double sign = (double)numerator / denominator;
	if (sign < 0) {
		cout << "   " << abs(numerator) << endl << "_ ";
		for (int i = 0; i < (max(number(abs(numerator)), number(abs(denominator))) + 2); i++) {
			cout << "_";
		} cout << endl;
		cout << "   " << abs(denominator) << endl << endl;
	}
	else if (sign > 0) {
		cout << " " << abs(numerator) << endl;
		for (int i = 0; i < (max(number(abs(numerator)), number(abs(denominator))) + 2); i++) {
			cout << "_";
		} cout << endl;
		cout << " " << abs(denominator) << endl << endl;
	}
	else if (sign == 0) {
		cout << "0" << endl << endl;
	}
}
void proper_fraction::cut_fraction() {
	int n = min(abs(numerator), abs(denominator));
	for (int i = n; i > 0; i--) {
		if (numerator % i == 0) {
			if (denominator % i == 0) {
				numerator = numerator / i;
				denominator = denominator / i;
			}
		}
	}
}
void proper_fraction::fraction_sum(int term) {
	numerator = numerator + term * denominator;
	cut_fraction();
}
void proper_fraction::fraction_sum(proper_fraction term) {
	this->numerator = this->numerator * term.denominator;
	term.numerator = term.numerator * this->denominator;
	this->denominator = term.denominator * this->denominator;
	this->numerator = this->numerator + term.numerator;
	cut_fraction();
}
void proper_fraction::fraction_multiplication(int factor) {
	numerator *= factor;
	cut_fraction();
}
void proper_fraction::fraction_multiplication(proper_fraction factor) {
	this->numerator = this->numerator * factor.numerator;
	this->denominator = this->denominator * factor.denominator;
	cut_fraction();
}
void proper_fraction::fraction_division(int divider) {
	if (divider == 0){
		cout << "denominator must be non-zero" << endl;
		exit(1);
	}
	denominator *= divider;
	cut_fraction();
}
void proper_fraction::fraction_division(proper_fraction divider) {
	this->numerator = this->numerator * divider.denominator;
	this->denominator = this->denominator * divider.numerator;
	cut_fraction();
}
int proper_fraction::get_fraction_numenator() {
	return numerator;
}
int proper_fraction::get_fraction_denominator() {
	return denominator;
}