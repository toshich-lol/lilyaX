#include <iostream>
#include <ctime>
using namespace std;
int main(){
    int size, prev, l, u, n, s, p, g;
    double  x;
    cout << "Enter size of array (>2): "<< endl;
    cin >> size;
    int *arr = new int[size];
    while (2 > size) {
        cout << "Enter an acceptable value " << endl;
        cin >> size;
    }
    cout << "If you want to see an array with random values, enter 1. If it isn't, enter other int and enter your values" << endl;
    cin >> x;
    if (x == 1) {
        cout << "Your choice is random. Enter lower bound and upper bound" << endl;
        srand(time(0));
        cin >> l >> u;
        if (u < l) {
            cout << "Enter an acceptable value" << endl;
            cin >> l >> u;
        }
        for (int i = 0; i < size; i++) {
            arr[i] = (rand() % (u - l + 1) + l);
        }
    }
    else{
        for (int i = 0; i < size; i++) {
            cin >> arr[i] ;
        }
    };
    n = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            n = n + 1;
        }
    }
    cout  << endl << "There is " << n << " positive elements in your array" << endl;
    s = 0;
    p = 0;
    g = 0;
    for (int i = (size - 1); i > (-1); i--) {
        if (arr[i] == 0) {
            p = p + 1;
        }
    }
    if (p > 0) {
        for (int i = (size - 1); i > (-1); i--) {
            s = s + arr[i];
            if (arr[i] == 0 && g < 1) {
                cout << "The sum of the array elements after the last zero element: " << s << endl;
                g = g + 1;
            }
        }
    }
    else{
        cout << "There is no zeros in your array" << endl;
    }
    cout << "Your not fxd array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i] << ",";
    }

    int const_prev = -1;
    for(int i=0; i<size;i++){
        if (arr[i]>0){
            const_prev=i;
            break;
        }
    }
    for (int i = 0; i < size; i++){
        prev = const_prev;
        for (int j = 0; j < size-i; j++) {
            if (arr[j] <= 0)
                continue;
            if (arr[prev] > arr[j]) {
                int a = arr[prev];
                arr[prev] = arr[j];
                arr[j] = a;
            }
            prev=j;
        }
    }

    int const_pre = -1;
    for(int i=0; i<size;i++){
        if (arr[i]<0){
            const_pre=i;
            break;}
    }
    for (int i = 0; i < size; i++){
        prev = const_pre;
        for (int j = 0; j < size-i; j++) {
            if (arr[j] >= 0)
                continue;
            if (arr[prev] < arr[j]) {
                int a = arr[prev];
                arr[prev] = arr[j];
                arr[j] = a;
            }
            prev=j;
        }
    }
    cout << "Your fixed array:" << endl;
    for (int i = 0; i < size; i++) {
        cout << " " << arr[i] << ",";
    }
    delete[] arr;
    return 0;
}