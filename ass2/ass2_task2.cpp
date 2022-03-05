#include <iostream>

int main()
{
    __int32 x;
    std::cout << "Enter x\n";
    std::cin >> x;
    if (x <= 0){
        std::cout << "Incorrect x\n";
        throw;
    }

    __asm{

        mov EBX, 10
        mov ECX, 0 
        mov EDX, 0
        mov EAX, x

        l1:
            div EBX
            inc ECX
            cmp EAX, 0
            mov EDX, 0
        jne l1
            mov EAX, 1
        l2:
            mul EBX
        loop l2
                
            mov ECX, EAX
            mov EAX, x
            mul EAX
            sub EAX, x
            div ECX
            mov x, EDX
    }
    if (x==0)
    {
        std::cout << "YES\n";
    }
    else
    {
        std::cout << "N0\n";
    }
    return 0;
}