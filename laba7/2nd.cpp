#include"2nd.h"
using namespace std;
    StudentAfterSecondSession::StudentAfterSecondSession(int course, const char name[100], int group, int RecordBookNumber, int FirstMark, int SecondMark, int ThirdMark, int FourthMark, int FivethMark, int SixthMark, int SeventhMark, int EighthMark, int NinethMark) : StudentAfterFirstSession(int(course), (char*)name, (int)group, (int)RecordBookNumber, (int)FirstMark, (int)SecondMark, (int)ThirdMark, (int)FourthMark) {
        marks_after_second_session[0] = FivethMark;
        marks_after_second_session[1] = SixthMark;
        marks_after_second_session[2] = SeventhMark;
        marks_after_second_session[3] = EighthMark;
        marks_after_second_session[4] = NinethMark;
    }
    StudentAfterSecondSession::StudentAfterSecondSession(const StudentAfterSecondSession& copy) : StudentAfterFirstSession(copy) {
        for (int i = 0; i < 5; i++)
        {
            this->marks_after_second_session[i] = copy.marks_after_second_session[i];
        }
    }
    void StudentAfterSecondSession::SetMarkAfterSecondSession(int mark, int number) {
        if (number > 4) {
            return;
        }
        marks_after_second_session[number - 1] = mark;
    }
    double StudentAfterSecondSession::AverageScore(){
        double sum(0);
        for (int i = 0; i < 4; i++)
        {
            sum += marks_after_first_session[i];
        }
        for (int i = 0; i < 4; i++)
        {
            sum += marks_after_second_session[i];
        }
        sum = (double)sum / 9;
        return sum;
    }
    int StudentAfterSecondSession::GetMarkAfterFirstSession(int number) {
        if (number > 4) {
            return -1;
        }
        return marks_after_first_session[number - 1];
    }
    int StudentAfterSecondSession::GetMarkAfterSecondSession(int number) {
        if (number > 4) {
            return -1;
        }
        return marks_after_second_session[number - 1];
    }
    ostream& operator << (ostream& out, const StudentAfterSecondSession& origin) {
        out << "Name: " << origin.name << "\nCourse: " << origin.course << "\nGroup: " << origin.group << "\nRecord book: " << origin.RecordBookNumber << "\nID: " << origin.identifier << "\nMarks:"
            << origin.marks_after_first_session[0] << " " << origin.marks_after_first_session[1] << " " << origin.marks_after_first_session[2] << " " << origin.marks_after_first_session[3] << " "
            << origin.marks_after_second_session[0] << " " << origin.marks_after_second_session[1] << " " << origin.marks_after_second_session[2] << " " << origin.marks_after_second_session[3] << " " << origin.marks_after_second_session[4];
        return out;
    }
