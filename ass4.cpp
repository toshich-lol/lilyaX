#include <iostream>
#include <iomanip>

int main()
{

    __int32  iteration(0), one(1), y(0), NF(0), two(2), noRoots(0);
    double a(0.5), b(0), c(0), x(0), intermediate(0), intermediate_rez(0), intermediate_rezult(0), rez(0), epsilon(0), root(0), higher_boder(10), lower_boder(-10), middle(0), zero(0);

    int number;

    std::cout << "Choose the task number: 1(b), 2(a), 3(a), or 5(c)\n";

    std::cin >> number;

    switch (number) {
    case 1:

        std::cout << "Enter a, b and c\n";
        std::cin >> a >> b >> c;
        __asm {

        counting:
                finit
                fld higher_boder
                fst x

                fmul x
                fmul x
                fstp intermediate_rezult
                fld x
                fmul x
                fmul a
                fadd intermediate_rezult
                fstp intermediate_rezult
                fld x
                fmul b
                fadd intermediate_rezult
                fadd c
                fst intermediate_rezult



                fcom zero
                fstsw ax
                sahf
                je is_root




                fld lower_boder
                fst x

                fmul x
                fmul x
                fstp intermediate_rezult
                fld x
                fmul x
                fmul a
                fadd intermediate_rezult
                fstp intermediate_rezult
                fld x
                fmul b
                fadd intermediate_rezult
                fadd c
                fst intermediate_rezult



                fcom zero
                fstsw ax
                sahf
                je is_root


                fmul ST, ST(1)
                fst root
                fcom zero
                fstsw ax
                sahf
                ja no_roots



                fld higher_boder
                fadd lower_boder
                fidiv two
                fst middle
                fst x

                fmul x
                fmul x
                fstp intermediate_rezult
                fld x
                fmul x
                fmul a
                fadd intermediate_rezult
                fstp intermediate_rezult
                fld x
                fmul b
                fadd intermediate_rezult
                fadd c
                fst intermediate_rezult





                fcom zero
                fstsw ax
                sahf
                je is_root

                fld intermediate_rezult

                fcom zero
                fstsw ax
                sahf
                ja change_higher_boder


                fld intermediate_rezult

                fcom zero
                fstsw ax
                sahf
                jb change_lower_boder



        change_higher_boder:

                fld middle
                fstp higher_boder
                jmp counting



        change_lower_boder:

            fld middle
            fstp lower_boder
            jmp counting



            is_root:
            fld x
            fstp root
            jmp end

        no_roots :

            inc noRoots
            jmp end

        end :


        }
        if (noRoots == 1){
            std::cout << "No roots\n";
        }
        else{
            std::cout << root << std::endl;
        }
        break;
    case 2:
            std::cout << "Enter required ouccuracy(5, 7 or 9)\n";
            std::cin >> y;
            switch (y) {
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
                    mov y, EAX
                    xor EDX, EDX
                    mov EAX, iteration
                    mov EBX, 2
                    div EBX
                    cmp EDX, 0
                    jne pos_
                    inc NF
                    pos_ :

                fld one
                    fdiv y
                    cmp NF, 0
                    je not_neg_
                    dec NF
                    fchs
                    not_neg_ :
                fadd intermediate_rez
                    fst intermediate_rez



                    mov y, 12
                    fimul y
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
        std::cin >> y;
        switch (y) {
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
                mov y, EAX


                fld one
                fdiv y
                fadd intermediate
                fstp intermediate



                fild one
                fadd intermediate
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
        std::cout << "Enter y\n";
        std::cin >> y;

        __asm {
            fild y
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
