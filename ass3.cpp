
#include <iostream>

int main(){

    int number;

    __int32 a, numenator, denominator;

    std::cout << "Choose the task number: 1, 2, 3, or 4\n";

    std::cin >> number;

    switch (number) {
    case 1:
        std::cout << "Enter a\n";

        std::cin >> a;

        __asm{
            mov EAX, a
            mul EAX
            mul EAX
            mov ECX, EAX
            mul ECX
            mov EBX, EAX
            mul ECX

            add EAX, EBX

            add EAX, a

            mov a, EAX
        }

        std::cout << "Result: " << a << std::endl;

        break;
    case 2:

        int solutions[16];

        __asm {
            mov EAX, 1
            mov EBX, 16
            xor ECX, ECX
        start_:
            mov [solutions + 4 * ECX], EAX
            inc ECX
            mov [solutions + 4 * ECX], EBX
            inc ECX
            add EAX, 3
            sub EBX, 2
            cmp EBX, 0 
            jg start_
        }

        for (int i = 0; i < 16; i+=2){
             std::cout << solutions[i] << " and " << solutions[i + 1] << std::endl;
        }
        break;
    case 3:

        int fib[48];
        __asm {

            xor EAX, EAX
            xor ECX, ECX
            mov [fib + 4 * ECX], EAX
            inc ECX
            mov[fib + 4 * ECX], ECX

        _begin:

            add EAX, [fib + 4 * ECX]
            jc _end
            inc ECX
            mov [fib + 4 * ECX], EAX
            mov EAX, [fib + 4 * ECX - 4]
            jmp _begin

        _end:

        }

        for (int i = 0; i < 47; i++){
            std::cout << fib[i] << ", ";
        }
        break;
    case 4:
        std::cout << "Enter numenator and denominator:\n";

        std::cin >> numenator >> denominator;


        if (denominator <= 0)
        {
            std::cout << "Incorrect denominator";
            throw;
        }

        __asm {
            mov EAX, numenator
            mov EBX, denominator
            xor EDX, EDX

            cmp EAX, 0
            jg begin_
            neg EAX

        begin_:

            cmp EAX, EBX
            je end_ 
            jg gr 
            sub EBX, EAX
            xor EDX, EDX
            jmp begin_

        gr:

            sub EAX, EBX
            xor EDX, EDX
            jmp begin_

        end_:
            
            mov ECX, EAX

            mov EAX, denominator
            div ECX
            mov denominator, EAX

            mov EAX, numenator
            xor EDX, EDX
            cmp numenator, 0
            jg finish

            neg EAX
            div ECX
            neg EAX
            jmp p1

        finish:

            div ECX

        p1:

            mov numenator, EAX
        }
        std::cout << numenator << "/" << denominator << std::endl;
        break;
    default:
        std::cout << "Incorrect number";
        throw;
    }
    return 0;
}
