#include <iostream>
using namespace std;
class Stack {
    int size;
    int* array = new int[size];
    int top;
    void resize(int a) {
        size += a;
        top += a;
        int* NewArray = new int[size];
        for (int i = 0; i < size; i++) {
            NewArray[i] = array[i];
        }
        delete[] array;
        array = NewArray;
    }
public:
    Stack() : size(0), top(-1) {}
    bool IsEmpty() {
        return !size;
    }

    void operator << (int value) {
        resize(1);
        array[top] = value;
    }
    int operator >> (int& deleted) {
        deleted = array[top];
        resize(-1);
        return deleted;
    }
    void operator = (Stack old) {
        resize(-size);
        resize(old.size);
        for (int i = 0; i < size; i++)
        {
            this->array[i] = old[i];
        }
    }
    bool operator == (Stack term) {
        return size == term.size;
    }
    bool operator < (Stack term) {
        return size < term.size;
    }
    bool operator > (Stack term) {
        return size > term.size;
    }
    int operator [] (int index) {
        if (index>top)
        {
            throw exception("Try correct index");
        }
        return array[index];
    }
    ~Stack() {
        delete[] array;
    }
};
int main()
{
    int b(0);
    Stack a;
    a << 3;
    a << 7;
    cout << a[4];
}