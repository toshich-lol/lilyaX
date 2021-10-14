#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main(){
    int size, word_end, word_begin, characteristic, best_characteristic, o;
    vector<int> vector_of_kords;
    vector<int> vector_of_characteristics;
    cout << "Enter your string" << endl;
    char* strone = new char[303]();
    cin.getline(strone, 303);
    for (int i = 301; i > 0; i--){
        strone[i] = strone[i - 1];
    }
    strone[0] = 32;
    for (int i = 0; i < 302; i++) {
        if (strone[i] == '\0'){
            size = i;
            break;
        }
    }
    strone[size] = 32;
    size++;
    for (int i = 0; i < size; i++) {
        if (strone[i] == 32 && strone[i + 1] != 32){
            word_begin = i;
            vector_of_kords.push_back(word_begin);
            for (int j = (i + 1); j < size; j++){
                if (strone[j] == 32) {
                    word_end = j;
                    vector_of_kords.push_back(word_end);
                    break;
                }
            }
        }
    }
    vector_of_kords.pop_back();
    int temp_first = 1;
    int temp_last = 304;
    best_characteristic = 304;
    for (int i = 0; i < (vector_of_kords.size() - 1); i++) {      // ходит по парам кордам
        for (int j = (vector_of_kords[i] + 1); j < vector_of_kords[i + 1]; j++) {         // ходит по буквам с которыми сравнивают
            for (int k = (vector_of_kords[i] + 1); k < vector_of_kords[i + 1]; k++) {        // ходит по буквам которые сравнивают
                if (strone[k] == strone[j])
                continue;
                else
                temp_first++;
            } 
            temp_last = min(temp_last, temp_first);
            temp_first = 1;
        }
        vector_of_characteristics.push_back(temp_last);
        i++;
        temp_last = 304;
    }
    cout << endl;
    for (int i = 0; i < (vector_of_characteristics.size() - 1); i++){
        best_characteristic = min(min(vector_of_characteristics[i], vector_of_characteristics[i + 1]), best_characteristic);
    }
   

    for (int i = 0; i < vector_of_characteristics.size(); i++) {
        if (vector_of_characteristics[i] == best_characteristic){
            o = i + 1;
            break;
        }
    }
    
    o = 2 * o;
    cout << "Your word is";
    for (int i = vector_of_kords[o-2]; i < vector_of_kords[o-1]; i++){
        cout << strone[i];
    }
}