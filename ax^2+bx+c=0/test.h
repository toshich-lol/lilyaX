#pragma once
#include "functions.h"
#include <cassert>
void test_func_1() {
    assert(desision(0, 0, 0) == 1);
}
void test_func_2() {
    assert(desision(2, 0, 0) == 2);
}
void test_func_3() {
    assert(desision(0, 2, 0) == 3);
}
void test_func_4() {
    assert(desision(0, 0, 2) == 4);
}
void test_func_5() {
    assert(desision(2, 2, 0) == 5);
}
void test_func_6() {
    assert(desision(0, 2, 2) == 6);
}
void test_func_7() {
    assert(desision(2, 0, -2) == 7);
}
void test_func_8() {
    assert(desision(2, 2, -2) == 8);
}
void test_func_9() {
    assert(desision(1, 2, 1) == 9);
}
void test_func_10() {
    assert(desision(2, 2, 2) == 10);
}
void run_tests(){
    test_func_1();
    test_func_2();
    test_func_3();
    test_func_4();
    test_func_5();
    test_func_6();
    test_func_7();
    test_func_8();
    test_func_9();
    test_func_10();
}