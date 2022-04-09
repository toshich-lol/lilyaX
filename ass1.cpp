#include <iostream>
#include <iomanip>

using namespace std;
int main() {

	__int16 a3, a2, a1;
	__int16 b3, b2, b1;
	__int32 c3(0), c2(0), c1(0);
	
	std::cout << "Enter numbers\n";
	std::cin >> a3 >> a2 >> a1;
	std::cin >> b3 >> b2 >> b1;

	__asm
	{
		xor EDX, EDX

		mov AX, a1
		add AX, b1
		mov c1, EAX

		mov AX, a2
		adc AX, b2
		mov c2, EAX

		mov AX, a3
		adc AX, b3
		mov c3, EAX

	}

	std::cout << c3 << " " << c2 << " " << c1 << std::endl;

	std::cout << hex << c3 << " " << c2 << " " << c1 << std::endl;

	return  0;
}
