
#include <iostream>

int main()
{
    int number;

    __int32 a, numenator, denominator;

    std::cout << "Choose the task number: 1, 2, 3, or 4\n";

    std::cin >> number;

    switch (number) {
    case 1:
        std::cout << "Enter a\n";

        std::cin >> a;

        __asm {
            mov EAX, a
            mul EAX
            mul EAX
            mov ECX, EAX; //4
            mul ECX
            mov EBX, EAX //8
            mul ECX

            add EAX, EBX

            add EAX, a

            mov a, EAX
        }

        std::cout << "Result: " << a << std::endl;

        break;
    case 2:

         __asm {
           
         }

        std::cout << "ASS result: "<< std::endl;
        break;
    case 3:
        __asm {
        
        }

        std::cout << "ASS result: "  << std::endl;
        break;
    case 4:
        std::cout << "Enter numenator and denominator:\n";

        std::cin >> numenator >> denominator;

        if (denominator <= 0)
        {
            std::cout << "Incorrecn denominator";
            throw;

            __asm {

            }
        }
        break;
    default:
        std::cout << "Incorrecn number";
        throw;
    }
    return 0;
}
