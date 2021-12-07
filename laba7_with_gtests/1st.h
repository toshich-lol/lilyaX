#pragma once
#include <iostream>
#include"student.h"
using namespace std;
class StudentAfterFirstSession : public student {
protected:
    int marks_after_first_session[4];
public:
    StudentAfterFirstSession(int course, const char name[100], int group, int RecordBookNumber, int FirstMark, int SecondMark, int ThirdMark, int FourthMark);
    StudentAfterFirstSession(const StudentAfterFirstSession& copy);
    void SetMarkAfterFirstSession(int mark, int number);
    virtual double AverageScore();
    int GetMarkAfterFirstSession(int number);
    friend ostream& operator << (ostream& out, const StudentAfterFirstSession& origin);
};
