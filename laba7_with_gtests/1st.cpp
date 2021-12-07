#include"1st.h"
#include <iostream>
using namespace std;
StudentAfterFirstSession::StudentAfterFirstSession(int course, const char name[100], int group, int RecordBookNumber, int FirstMark, int SecondMark, int ThirdMark, int FourthMark) : student((int)course, (char*)name, int(group), int(RecordBookNumber)) {
    marks_after_first_session[0] = FirstMark;
    marks_after_first_session[1] = SecondMark;
    marks_after_first_session[2] = ThirdMark;
    marks_after_first_session[3] = FourthMark;
}
StudentAfterFirstSession::StudentAfterFirstSession(const StudentAfterFirstSession& copy) : student(copy) {
    for (int i = 0; i < 4; i++) {
        this->marks_after_first_session[i] = copy.marks_after_first_session[i];
    }
}
void StudentAfterFirstSession::SetMarkAfterFirstSession(int mark, int number) {

    if (number > 4) {
        return;
    }
    marks_after_first_session[number - 1] = mark;
}
double StudentAfterFirstSession::AverageScore() {
    double sum(0);
    for (int i = 0; i < 4; i++)
    {
        sum += marks_after_first_session[i];
    }
    sum = (double)sum / 4;
    return sum;
}
int StudentAfterFirstSession::GetMarkAfterFirstSession(int number) {
    if (number > 4) {
        return -1;
    }
    return marks_after_first_session[number - 1];
}
ostream& operator << (ostream& out, const StudentAfterFirstSession& origin) {
    out << "Name: " << origin.name << "\nCourse: " << origin.course << "\nGroup: " << origin.group << "\nRecord book: " << origin.RecordBookNumber << "\nID: " << origin.identifier << "\nMarks:" << origin.marks_after_first_session[0] << " " << origin.marks_after_first_session[1] << " " << origin.marks_after_first_session[2] << " " << origin.marks_after_first_session[3];
    return out;
}

