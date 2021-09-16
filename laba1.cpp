#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main() {
    setlocale(LC_ALL, "Rus");
    int k, n, c, q;
    double x, f, w, s;
    cout << "Now enter x" << endl;
    cin >> x;
    while (x <= -1 || x >= 1) {
        cout << "Enter an acceptable value for the number x" << endl;
        cin >> x;
    }
    f = acos(-1) / 2;
    n = 1;
    c = -1;
    cout << "Now enter the number k." << endl;
    cin >> k;
    while (k < 1) {
        cout << "Enter an acceptable value for the number k" << endl;
        cin >> k;
    }
    q = (-1) * k;
    w = pow(10, q);
    cout << w << endl;
    do {
        s = pow(x, n);
        s = s / n;
        s = s * c;
        c = (-1) * c;
        n = n + 2;
        f = f + s;
    } while (fabs(s) > w);
    cout << "arcctg =" << setprecision(k) << f;
}