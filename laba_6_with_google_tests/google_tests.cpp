#include"proper_fraction.h"
#include "gtest/gtest.h"
TEST(get_fraction_numenator,test1){
proper_fraction dr(3, 5);
    ASSERT_EQ(dr.get_fraction_numenator(), 3);
}
TEST(get_fraction_denominator,test2){
    proper_fraction dr(3, 5);
    ASSERT_EQ(dr.get_fraction_denominator(), 5);
}
TEST(copy_constructor,test3){
    proper_fraction dr(3, 5);
    proper_fraction dr1(dr);
    ASSERT_EQ(dr1.get_fraction_numenator(), 3);
    ASSERT_EQ(dr1.get_fraction_denominator(), 5);
}
TEST(cut_fraction,test4_proper_fraction_one){
    proper_fraction dr(6, 6);
    ASSERT_EQ(dr.get_fraction_numenator(), 1);
    ASSERT_EQ(dr.get_fraction_denominator(), 1);
}
TEST(cut_fraction,test4_proper_fraction){
    proper_fraction dr(6, 10);
    ASSERT_EQ(dr.get_fraction_numenator(), 3);
    ASSERT_EQ(dr.get_fraction_denominator(), 5);
}
TEST(cut_fraction,test4_non_proper_fraction){
    proper_fraction dr(6, 10);
    dr.fraction_multiplication(3);
    ASSERT_EQ(dr.get_fraction_numenator(), 9);
    ASSERT_EQ(dr.get_fraction_denominator(), 5);
}
TEST(cut_fraction,test4_proper_fraction_double_minus){
    proper_fraction dr(-6, -10);
    ASSERT_EQ(dr.get_fraction_numenator(), -3);
    ASSERT_EQ(dr.get_fraction_denominator(), -5);
}
TEST(cut_fraction,test4_proper_fraction_once_minus){
    proper_fraction dr(-6, 10);
    ASSERT_EQ(dr.get_fraction_numenator(), -3);
    ASSERT_EQ(dr.get_fraction_denominator(), 5);
}
TEST(fraction_sum_int,test5_witn_positive){
    proper_fraction dr(3, 5);
    dr.fraction_sum(4);
    ASSERT_EQ(dr.get_fraction_numenator(), 23);
    ASSERT_EQ(dr.get_fraction_denominator(), 5);
}
TEST(fraction_sum_int,test5_with_negative){
    proper_fraction dr(3, 5);
    dr.fraction_sum(-4);
    ASSERT_EQ(dr.get_fraction_numenator(), -17);
    ASSERT_EQ(dr.get_fraction_denominator(), 5);
}
TEST(fraction_sum_int,test5_with_zero){
    proper_fraction dr(3, 5);
    dr.fraction_sum(0);
    ASSERT_EQ(dr.get_fraction_numenator(), 3);
    ASSERT_EQ(dr.get_fraction_denominator(), 5);
}
TEST(fraction_sum_proper_fraction,test6_with_positive){
    proper_fraction dr(3, 5);
    proper_fraction dr1(9,10);
    dr.fraction_sum(dr1);
    ASSERT_EQ(dr.get_fraction_numenator(), 3);
    ASSERT_EQ(dr.get_fraction_denominator(), 2);
}
TEST(fraction_sum_proper_fraction,test6_with_negative){
    proper_fraction dr(3, 5);
    proper_fraction dr1(-9,10);
    dr.fraction_sum(dr1);
    ASSERT_EQ(dr.get_fraction_numenator(), -3);
    ASSERT_EQ(dr.get_fraction_denominator(), 10);
}
TEST(fraction_sum_proper_fraction,test6_with_zero){
    proper_fraction dr(3, 5);
    proper_fraction dr1(0,10);
    dr.fraction_sum(dr1);
    ASSERT_EQ(dr.get_fraction_numenator(), 3);
    ASSERT_EQ(dr.get_fraction_denominator(), 5);
}
TEST(fraction_multiplication_int,test7_with_positive){
    proper_fraction dr(3, 5);
    dr.fraction_multiplication(4);
    ASSERT_EQ(dr.get_fraction_numenator(), 12);
    ASSERT_EQ(dr.get_fraction_denominator(), 5);
}
TEST(fraction_multiplication_int,test7_with_zero){
    proper_fraction dr(3, 5);
    dr.fraction_multiplication(0);
    ASSERT_EQ(dr.get_fraction_numenator(), 0);
    ASSERT_EQ(dr.get_fraction_denominator(), 5);
}
TEST(fraction_multiplication_int,test7_with_negative){
    proper_fraction dr(3, 5);
    dr.fraction_multiplication(-4);
    ASSERT_EQ(dr.get_fraction_numenator(), -12);
    ASSERT_EQ(dr.get_fraction_denominator(), 5);
}
TEST(fraction_multiplication_proper_fraction,test8_with_positive){
    proper_fraction dr(3, 5);
    proper_fraction dr1(9,10);
    dr.fraction_multiplication(dr1);
    ASSERT_EQ(dr.get_fraction_numenator(), 27);
    ASSERT_EQ(dr.get_fraction_denominator(), 50);
}
TEST(fraction_multiplication_proper_fraction,test8_with_zero){
    proper_fraction dr(3, 5);
    proper_fraction dr1(0,10);
    dr.fraction_multiplication(dr1);
    ASSERT_EQ(dr.get_fraction_numenator(), 0);
    ASSERT_EQ(dr.get_fraction_denominator(), 50);
}
TEST(fraction_multiplication_proper_fraction,test8_with_negative){
    proper_fraction dr(3, 5);
    proper_fraction dr1(-9,10);
    dr.fraction_multiplication(dr1);
    ASSERT_EQ(dr.get_fraction_numenator(), -27);
    ASSERT_EQ(dr.get_fraction_denominator(), 50);
}

TEST(fraction_division_int,test9_with_positive){
    proper_fraction dr(3, 5);
    dr.fraction_division(4);
    ASSERT_EQ(dr.get_fraction_numenator(), 3);
    ASSERT_EQ(dr.get_fraction_denominator(), 20);
}
TEST(fraction_division_int,test9_with_negative){
    proper_fraction dr(3, 5);
    dr.fraction_division(-4);
    ASSERT_EQ(dr.get_fraction_numenator(), 3);
    ASSERT_EQ(dr.get_fraction_denominator(), -20);
}
TEST(fraction_division_proper_fraction,test10_with_positive){
    proper_fraction dr(3, 5);
    proper_fraction dr1(9,10);
    dr.fraction_division(dr1);
    ASSERT_EQ(dr.get_fraction_numenator(), 2);
    ASSERT_EQ(dr.get_fraction_denominator(), 3);
}
TEST(fraction_division_proper_fraction,test10_with_negative){
    proper_fraction dr(3, 5);
    proper_fraction dr1(-9,10);
    dr.fraction_division(dr1);
    ASSERT_EQ(dr.get_fraction_numenator(), 2);
    ASSERT_EQ(dr.get_fraction_denominator(), -3);
}