#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void transformer(vector<vector<int>> & mtr ,int i, int j, int c) {
    if (j >= c){
        j = j - c;
        cout << (-1) * mtr[i][j] << ' ';
    }
    else {
        cout << mtr[i][j] << ' ';
    }
 }

int main() {
    int r, c;
    cout << "Enter the number of rows and colums (divided by two)" << endl;
    cin >> r >> c;
    while (r > 10 || c > 10) {
        cout << "Enter an acceptable values " << endl;
        cin >> r >> c;
    }
    vector<vector<int>> mtr(r, vector <int>(c));
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
        {
            cout << "mtr[" << i << "][" << j << "] = ";
            cin >> mtr[i][j];
        }
    cout << "Your matrix:" << endl;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
            cout << mtr[i][j] << ' ';
        cout << endl;
    }
    vector <int> vec(c, 0);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++) {
            vec[j] = vec[j] + abs(mtr[i][j]);
        }
    }
  

    vector<int> stat(c);
    stat = vec;
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            for (int q = 0; q < c - (j + 1); q++) {
                if (vec[q] > vec[q + 1]) {
                    swap(vec[q], vec[q + 1]);
                    swap(mtr[i][q], mtr[i][q + 1]);
                }
            }
        }
        vec = stat;
    }
    cout << "Your fixed matrix:" << endl;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < (2 * c); j++) {
            transformer(mtr, i, j, c);
        }
        cout << endl;
    }


    return 0;
}

/*13.	В целочисленной прямоугольной матрице, имеющей 2n столбцов, a[i, j] = -a[i, j+n] для всех допустимых i и j.
 * Характеристикой столбца прямоугольной матрицы называется сумма модулей его элементов.
 * Перестроить заданную матрицу, переставляя в ней столбцы так, чтобы значения их характеристик убывали.
 *
 * В задании память для исходной матрицы выделяется динамически в объеме, минимально необходимом для хранения данных, размерности массивов не превосходят 10.
Необходимо:
-	осуществить проверку на правильность ввода размерности массивов;
-	организовать удобный для пользователя ввод данных (без ввода лишних данных);
-	построчно вывести на консоль введенную матрицу;
-	расчеты выполнять так, будто матрица хранится целиком. Для обращения к элементам написать соответствующие функции;
-	вывести результаты расчетов.
*/