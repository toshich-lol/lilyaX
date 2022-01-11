#pragma once
using namespace std;
template<typename T>
class Stack {
    int size;
    T* array = new T[size];
    int top;
public:
    Stack();
    bool IsEmpty();
    void resize(int a);
    T GetTop();
    void operator << (T value);
    T operator >> (T& deleted);
    T pop();
    void operator = (Stack old);
    bool operator == (Stack term);
    bool operator < (Stack term);
    bool operator > (Stack term);
    T operator [] (int index) ;
    ~Stack();
};
template <typename T>
Stack<T>::Stack() : size(0), top(-1) {}
template <typename T>
bool Stack<T>::IsEmpty() {
    return !size;
}
template <typename T>
void Stack<T>::resize(int a) {
    size += a;
    top += a;
    T* NewArray = new T[size];
    for (int i = 0; i < size; i++) {
        NewArray[i] = array[i];
    }
    delete[] array;
    array = NewArray;
}
template <typename T>
void Stack<T>::operator << (T value) {
    resize(1);
    array[top] = value;
}
template <typename T>
T Stack<T>::GetTop(){
    return array[top];
}
template <typename T>
T Stack<T>::operator >> (T& deleted) {
    deleted = array[top];
    resize(-1);
    return deleted;
}
template<typename T>
T Stack<T>::pop() {
    T deleted = array[top];
    resize(-1);
    return deleted;
}
template <typename T>
void Stack<T>::operator = (Stack<T> old) {
    resize(-size);
    resize(old.size);
    for (int i = 0; i < size; i++)
    {
        this->array[i] = old[i];
    }
}
template <typename T>
bool Stack<T>::operator == (Stack<T> term) {
    return size == term.size;
}
template <typename T>
bool Stack<T>::operator < (Stack<T> term) {
    return size < term.size;
}
template <typename T>
    bool Stack<T>::operator > (Stack<T> term) {
        return size > term.size;
    }
template <typename T>
T Stack<T>::operator [] (int index) {
    if (index>top)
    {
        throw exception("Try correct index");
    }
    return array[index];
}
template <typename T>
Stack<T>::~Stack() {
    delete[] array;
}