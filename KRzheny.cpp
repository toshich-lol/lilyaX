#include <iomanip>
#include <iostream>
int main()
{
	int n(4);
	__int32 cut(0b00001111111111111001111110000000);//268410752

	unsigned int ky[4]{0b00010000000000010000000000000000, 0b00100000000000001000000000000000, 0b01000000000000000000001000000000, 0b10000000000000000000000010000000};
	std::cout << "Enter numbers\n";


	//268500992 
	//536903680
	//1073742336
	//2147483776
	

	__asm {
		xor EDX, EDX
        xor EAX, EAX
        xor ECX, ECX
		xor EBX, EBX
		
		for_out:

		push ECX
		xor ECX, ECX
		for_in:

		
		mov EAX, [ky + 4 * ECX]
		and EAX, cut
		mov EDX, [ky + 4 * ECX + 4]
		and EDX, cut


		cmp EDX, EAX
		jg no_rev_

		mov EDX, [ky + 4 * ECX]
		mov EAX, [ky + 4 * ECX + 4]
		mov [ky + 4 * ECX + 4], EDX
		mov [ky + 4 * ECX], EAX

		no_rev_:

		inc ECX
		cmp ECX, n
		jge end_in
		jmp for_in


		end_in:
		
		pop	ECX
		inc ECX
		cmp ECX, n
		jge end_out
		jmp for_out


		end_out:
    }
	for (int i = 0; i < 4; i++){
		std::cout << ky[i] << " ";
	}
}

