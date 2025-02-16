#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student
{
public:
    Student(const string &name, int age);
    void setAge(int);
    void setName(string);
    string getName();
    int getAge();
    void printStudentInfo() const;
private:
    string Name;
    int Age;

};

#endif // STUDENT_H
