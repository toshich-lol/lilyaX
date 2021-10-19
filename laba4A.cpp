#include <iostream>
using namespace std;
char strkitten(char* strone, char* strtwo) {
    int last_sigh;
    cin.getline(strone, 600);
    cin.getline(strtwo, 300);
    for (int i = 0; i < 300; i++) {
        if (strone[i] == '\0') {
            last_sigh = i;
            break;
        }
    }
    for (int i = last_sigh; i < 600; i++) {
        strone[i] = strtwo[i - last_sigh];
    }
    return *strone;
}
int main() {
    cout << "Enter first string" << endl;
    char* strone = new char[600]();
    cout << "Enter second string" << endl;
    char* strtwo = new char[300]();
    strkitten(strone, strtwo);
    cout << "Your kitten-string\t" << strone;

    delete[] strone;
    delete[] strtwo;
}