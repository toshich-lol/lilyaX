#include "gtest/gtest.h"
#include "2nd.h"
TEST(student_, constructor){
    student test(1, "test", 4, 5);
    ASSERT_EQ(test.GetCourse(), 1);
    ASSERT_EQ(test.GetGroup(),4 );
    ASSERT_EQ(test.GetRecordBookNumber(), 5 );
    ASSERT_EQ(test.GetID(), 1);
}
TEST(student_,setters){
    student test(1, "test", 4, 5);
    test.SetCourse(2);
    test.SetGroup(5);
    ASSERT_EQ(test.GetCourse(), 2);
    ASSERT_EQ(test.GetGroup(),5);
    ASSERT_EQ(test.GetID(), 2);
}
TEST(student_, CopyConstructor){
    student test(1, "test", 4, 5);
    student copy(test);
    ASSERT_EQ(copy.GetCourse(), 1);
    ASSERT_EQ(copy.GetGroup(),4 );
    ASSERT_EQ(copy.GetRecordBookNumber(), 5 );
    ASSERT_EQ(copy.GetID(), 4);
}
TEST(StudentAfterFirstSession_, constructor){
    StudentAfterFirstSession test(1,"test", 4, 666,1,2,3,4);
    ASSERT_EQ(test.GetMarkAfterFirstSession(1), 1);
    ASSERT_EQ(test.GetMarkAfterFirstSession(2),2 );
    ASSERT_EQ(test.GetMarkAfterFirstSession(3), 3 );
    ASSERT_EQ(test.GetMarkAfterFirstSession(4), 4);
}
TEST(StudentAfterFirstSession_, CopyConstructor){
    StudentAfterFirstSession test(1,"test", 4, 666,1,2,3,4);
    StudentAfterFirstSession copy(test);
    ASSERT_EQ(copy.GetMarkAfterFirstSession(1), 1);
    ASSERT_EQ(copy.GetMarkAfterFirstSession(2),2 );
    ASSERT_EQ(copy.GetMarkAfterFirstSession(3), 3 );
    ASSERT_EQ(copy.GetMarkAfterFirstSession(4), 4);
}
TEST(StudentAfterFirstSession_, setters){
    StudentAfterFirstSession test(1,"test", 4, 666,0,0,0,0);
    test.SetMarkAfterFirstSession(1,1);
    test.SetMarkAfterFirstSession(2,2);
    test.SetMarkAfterFirstSession(3,3);
    test.SetMarkAfterFirstSession(4,4);
    ASSERT_EQ(test.GetMarkAfterFirstSession(1), 1);
    ASSERT_EQ(test.GetMarkAfterFirstSession(2),2 );
    ASSERT_EQ(test.GetMarkAfterFirstSession(3), 3 );
    ASSERT_EQ(test.GetMarkAfterFirstSession(4), 4);
}
TEST(StudentAfterFirstSession_, avarage){
    StudentAfterFirstSession test(1,"test", 4, 666,3,2,3,4);
    ASSERT_EQ(test.AverageScore(),3 );
}
TEST(StudentAfterSecondSession_, constructor){
    StudentAfterSecondSession test(1,"test", 4, 666,1,2,3,4,5,6,7,8,9);
    ASSERT_EQ(test.GetMarkAfterFirstSession(1), 1);
    ASSERT_EQ(test.GetMarkAfterFirstSession(2),2 );
    ASSERT_EQ(test.GetMarkAfterFirstSession(3), 3 );
    ASSERT_EQ(test.GetMarkAfterFirstSession(4), 4);
    ASSERT_EQ(test.GetMarkAfterSecondSession(1), 5);
    ASSERT_EQ(test.GetMarkAfterSecondSession(2),6);
    ASSERT_EQ(test.GetMarkAfterSecondSession(3), 7 );
    ASSERT_EQ(test.GetMarkAfterSecondSession(4), 8);
    ASSERT_EQ(test.GetMarkAfterSecondSession(5), 9);
}
TEST(StudentAfterSecondSession_, CopyConstructor){
    StudentAfterSecondSession test(1,"test", 4, 666,1,2,3,4,5,6,7,8,9);
    StudentAfterSecondSession copy(test);
    ASSERT_EQ(copy.GetMarkAfterFirstSession(1), 1);
    ASSERT_EQ(copy.GetMarkAfterFirstSession(2),2 );
    ASSERT_EQ(copy.GetMarkAfterFirstSession(3), 3 );
    ASSERT_EQ(copy.GetMarkAfterFirstSession(4), 4);
    ASSERT_EQ(copy.GetMarkAfterSecondSession(1), 5);
    ASSERT_EQ(copy.GetMarkAfterSecondSession(2),6);
    ASSERT_EQ(copy.GetMarkAfterSecondSession(3), 7 );
    ASSERT_EQ(copy.GetMarkAfterSecondSession(4), 8);
    ASSERT_EQ(copy.GetMarkAfterSecondSession(5), 9);
}
TEST(StudentAfterSecondSession_, setters) {
    StudentAfterSecondSession test(1, "test", 4, 666, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    test.SetMarkAfterSecondSession(5, 1);
    test.SetMarkAfterSecondSession(6, 2);
    test.SetMarkAfterSecondSession(7, 3);
    test.SetMarkAfterSecondSession(8, 4);
    test.SetMarkAfterSecondSession(9, 5);
    ASSERT_EQ(test.GetMarkAfterSecondSession(1), 5);
    ASSERT_EQ(test.GetMarkAfterSecondSession(2),6);
    ASSERT_EQ(test.GetMarkAfterSecondSession(3), 7 );
    ASSERT_EQ(test.GetMarkAfterSecondSession(4), 8);
    ASSERT_EQ(test.GetMarkAfterSecondSession(5), 9);
}
TEST(StudentAfterSecondSession_, avarage){
        StudentAfterSecondSession test(1,"test", 4, 666,6,6,7,9,5,6,7,8,9);
    ASSERT_EQ(test.AverageScore(),7 );
}
