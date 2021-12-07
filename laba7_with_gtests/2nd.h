#pragma once
#include "1st.h"
class StudentAfterSecondSession : public StudentAfterFirstSession {
    int marks_after_second_session[5];
public:
    StudentAfterSecondSession(int course, const char name[100], int group, int RecordBookNumber, int FirstMark, int SecondMark, int ThirdMark, int FourthMark, int FivethMark, int SixthMark, int SeventhMark, int EighthMark, int NinethMark);
    StudentAfterSecondSession(const StudentAfterSecondSession& copy);
    void SetMarkAfterSecondSession(int mark, int number);
    double AverageScore() override;
    int GetMarkAfterFirstSession(int number);
    int GetMarkAfterSecondSession(int number);
    friend ostream& operator << (ostream& out, const StudentAfterSecondSession& origin);;
};
