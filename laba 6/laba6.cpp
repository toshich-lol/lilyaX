#include <iostream>
#include"proper_fraction.h"
using namespace std;
int main()
{
	proper_fraction dr(-5,25);
	proper_fraction dr1(-6, 7);
	dr.fraction_sum(dr1);

	dr.print();

	return 0;
}
