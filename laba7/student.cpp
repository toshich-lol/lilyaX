#include"student.h"
#include <iostream>
using namespace std;
    int student::count = 0;
    student::student(int course, const char name[100], int group, int _RecordBookNumber) :RecordBookNumber(_RecordBookNumber) {
    int size(0);
    for (int i = 0; i < 100; i++)
    {
        if (name[i] == '\0')
        {
            size = i;
            break;
        }
    }
    this->name = new char[size + 1];
    for (int i = 0; i < size; i++)
    {
        this->name[i] = name[i];
    }
    this->name[size] = '\0';
    this->course = course;
    this->group = group;
    count++;
    identifier = count;
}
    student::student(const student& copy) :RecordBookNumber(copy.RecordBookNumber) {
        int size(0);
        for (int i = 0; i < 100; i++)
        {
            if (copy.name[i] == '\0')
            {
                size = i;
                break;
            }
        }
        this->name = new char[size + 1];
        for (int i = 0; i < size; i++)
        {
            this->name[i] = copy.name[i];
        }
        this->name[size] = '\0';
        this->course = copy.course;
        this->group = copy.group;
        count++;
        identifier = count;
    }
    void student::SetCourse(int course) {
        this->course = course;
    }
    void student::SetGroup(int group) {
        this->group = group;
    }
    void student::SetName(char* name) {
        this->name = name;
    }
    char* student::GetName() {
        return name;
    }
    int student::GetID() {
        return identifier;
    }
    int student::GetCourse() {
        return course;
    }
    int student::GetGroup() {
        return group;
    }
    int student::GetRecordBookNumber() {
        return RecordBookNumber;
    }
    student::~student() {
        delete[] name;
    }
    ostream& operator << (ostream& out, const student& origin) {
        out << "Name: " << origin.name << "\nCourse: " << origin.course << "\nGroup: " << origin.group << "\nRecord book: " << origin.RecordBookNumber << "\nID: " << origin.identifier;
        return out;
    }