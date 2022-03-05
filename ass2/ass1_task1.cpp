
#include <cmath>
#include <iostream>

int main()
{
    int number;
    __int32 x;
    std::cout << "Choose the desision number: 1, 2, or 3\n";

    std::cin >> number;

    std::cout << "Enter x\n";

    std::cin >> x;

    switch (number){
    case 1:
        if (x == 0) {
            std::cout << "Incorrect x\n";
            throw;
        }
        std::cout << "C++ result: " << int((pow(x, 5) + 2 * (pow(x, 2) - 4) + x) / pow(x, 3)) << std::endl;
        __asm {
            mov EAX, x
            imul x
            imul EAX
            imul x
            add EAX, x
            mov ECX, EAX

            mov EAX, x
            imul x
            sub EAX, 4
            add EAX, EAX
            add EAX, ECX
            mov EBX, EAX
            
            mov EAX, x
            imul x
            imul x
            mov ECX, EAX
            mov EAX, EBX

            idiv ECX

            mov x, EAX
        }
        std::cout << "ASS result: " << x << std::endl;
        break;
    case 2:
        if (x == 0) {
            std::cout << "Incorrect x\n";
            throw;
        }
        std::cout << "C++ result: " << int((2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x)) << std::endl;
        __asm {
            mov EAX, x
            add EAX, EAX
            sub EAX, 1
            mov ECX, EAX

            add EAX, 2
            imul ECX
            mov ECX, EAX

            mov EAX, x
            add EAX, 3
            imul ECX
            mov ECX, EAX

            mov EAX, x
            add EAX, EAX
            mov EBX, EAX
            mov EAX, ECX

            idiv EBX

            mov x, EAX
        }
        std::cout << "ASS result: " << x << std::endl;
        break;
    case 3:
        std::cout << "C++ result: " << int((4 * x - 1) * (4 * x + 1) / 4) << std::endl;
        __asm {
            mov EBX, 4
            mov EAX, x
            imul EBX
            sub EAX, 1
            mov ECX, EAX

            add EAX, 2
            imul ECX

            idiv EBX

            mov x, EAX
        }
        std::cout << "ASS result: " << x << std::endl;
        break;
    default:
        std::cout << "Incorrecn number";
            throw;
    }
    return 0;
}

