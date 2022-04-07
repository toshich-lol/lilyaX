#include <iostream>
#include <iomanip>

int main()
{

    __int32  iteration(0), one(1), x(0), NF(0), two(2);
    double a(0.5), intermediat_rez(0), intermediat_rezult(0), rez(0), epsilon(0);

    int number;

    std::cout << "Choose the task number: 1(b), 2(a), 3(a), or 5(c)\n";

    std::cin >> number;

    switch (number) {
    case 1:
        std::cout << "Enter x\n";;
        __asm {

        }

        std::cout << "Result: " << std::endl;

        break;
    case 2:
            std::cout << "Enter required ouccuracy(5, 7 or 9)\n";
            std::cin >> x;
            switch (x) {
            case 5:
                epsilon = 0.000001;
                break;
            case 7:
                epsilon = 0.00000001;
                break;
            case 9:
                epsilon = 0.0000000001;
                break;
            default:
                std::cout << "You have 3 option: 1,2 or 3. Choose wisely\n";
                throw;
            }
            __asm {


            count:
                finit
                    xor EDX, EDX
                    inc iteration
                    mov EAX, iteration
                    mul EAX
                    mov x, EAX
                    xor EDX, EDX
                    mov EAX, iteration
                    mov EBX, 2
                    div EBX
                    cmp EDX, 0
                    jne pos_
                    inc NF
                    pos_ :

                fld one
                    fdiv x
                    cmp NF, 0
                    je not_neg_
                    dec NF
                    fchs
                    not_neg_ :
                fadd intermediat_rez
                    fst intermediat_rez



                    mov x, 12
                    fimul x
                    fsqrt
                    fst rez

                    fldpi
                    fsub
                    fabs

                    fcom epsilon

                    fstsw ax
                    sahf
                    jnc count

            }

            std::cout << "It needs " << iteration << " of iteration to get this epsilon\n";

            std::cout << std::setprecision(15) << "Our PI = " << rez << ", PI = 3.141592653\n";

        break;
    case 3:

        std::cout << "Enter required epsilon (2, 3 or 4)\n";
        std::cin >> x;
        switch (x) {
        case 2:
            epsilon = 0.001;
            break;
        case 3:
            epsilon = 0.0001;
            break;
        case 4:
            epsilon = 0.00001;
            break;

        default:
            std::cout << "You have to choose between 2, 3 or 4";
            throw;
            break;
        }
        __asm {

        count_:
            finit
                xor EDX, EDX
                inc iteration
                mov EAX, iteration
                mul EAX
                mov EDX, 4
                mul EDX
                xor EDX, EDX
                sub EAX, 1
                mov EBX, iteration
                mul EBX
                mov x, EAX


                fld one
                fdiv x
                fadd intermediat_rezult
                fstp intermediat_rezult



                fild one
                fadd intermediat_rezult
                fidiv two
                fst rez

                fldln2
                fsub
                fabs
                fcom epsilon
                fstsw ax
                sahf
                jnc count_
        }

        std::cout << "It needs " << iteration << " of itertion to get this epsilon\n";

        std::cout << "Our ln2 = " << std::setprecision(10) << rez << " ln2 = 0.69314718\n";

        break;
    case 5:
        std::cout << "Enter x\n";
        std::cin >> x;

        __asm {
            fild x
            fld a
            FYL2X
            fild one
            FSCALE
            fst a
        }

        std::cout << a << std::endl;

        break;
    default:
        std::cout << "Incorrect number";
        throw;
    }
    return 0;
}
