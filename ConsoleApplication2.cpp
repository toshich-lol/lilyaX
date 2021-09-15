#include <iostream>; 
#include <cmath>
#include <iomanip> 
using namespace std;
int main() {
    setlocale(LC_ALL, "Rus");
    int k, n, c, q; 
    double x, f, w, s ;
    cout << "Женя, введи число, арккотангенс которого ты хочешь узнать.Его значение должно принадлежать промежутку(-1; 1)" << endl;
    cin >> x;
        while (x <= -1 || x >= 1) {
        cout << "Введите приемлимое значение числа" << endl;
        cin >> x;
        }
    f = acos(-1) / 2;
    n = 1;
    c = -1;
    cout << "Теперь введи число k. Оно должно быть натуральным." << endl;
    cin >> k;
        while (k < 1) {
        cout << "Введите приемлимое значение числа k" << endl;
        cin >> k;
        }
            
    q = (-1) * k;
    w = pow(10, q);
    cout << w << endl ;
        do {
            s = pow(x, n);
            s = s / n;
            s = s * c;
            c = (-1) * c;
            n = n + 2;
            f = f + s;
        } while (fabs(s) > w);
    cout << "Твоё значение arcctg =" << f;
}