#pragma once
#include <iostream>
using namespace std;
class student {
protected:
    const int RecordBookNumber;
    int identifier;
    int course;
    int group;
    static int count;
    char* name;
public:
    student(int course, const char name[100], int group, int _RecordBookNumber);
    student(const student& copy);
    void SetCourse(int course);
    void SetGroup(int group);
    void SetName(char* name);
    char* GetName();
    int GetID();
    int GetCourse();
    int GetGroup();
    int GetRecordBookNumber();
    virtual ~student();
    friend ostream& operator << (ostream& out, const student& origin);
};

