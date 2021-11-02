#pragma once
#include <cassert>
#include "strkitten.h"
void test_func_1() {
    char* array_test1 = new char[600]{ "hello" };
    char* array_test2 = new char[300]{ "world" };
    char* result = new char[600]{"helloworld"};

    strkitten(array_test1, array_test2);
    for (int i = 0; result[i] != '\0'; ++i) {
        assert(array_test1[i] == result[i]);
    };
    delete[] result;
    delete[] array_test1;
    delete[] array_test2;
}   
void test_func_2() {
    char* array_test1 = new char[600]{'\0'};
    char* array_test2 = new char[300]{'\0'};
    char* result = new char[600]{ '\0'};
    strkitten(array_test1, array_test2);
    for (int i = 0; result[i] != '\0'; ++i) {
        assert(array_test1[i] == result[i]);
    };
    delete[] result;
    delete[] array_test1;
    delete[] array_test2;
}
void test_func_3() {
    char* array_test1 = new char[600]{ "aboba" };
    char* array_test2 = new char[300]{ '\0' };
    char* result = new char[600]{ "aboba" };
    strkitten(array_test1, array_test2);
    for (int i = 0; result[i] != '\0'; ++i) {
        assert(array_test1[i] == result[i]);
    }
    delete[] result;
    delete[] array_test1;
    delete[] array_test2;
}
void test_func_4(){
        char* array_test1 = new char[600]{ '\0' };
        char* array_test2 = new char[300]{ "aboba" };
        char* result = new char[600]{ "aboba" };
        strkitten(array_test1, array_test2);
        for (int i = 0; result[i] != '\0'; ++i) {
            assert(array_test1[i] == result[i]);
        };
        delete[] result;
        delete[] array_test1;
        delete[] array_test2;
    }
void run_tests() {
    test_func_1();
    test_func_2();
    test_func_3();
    test_func_4();
}
