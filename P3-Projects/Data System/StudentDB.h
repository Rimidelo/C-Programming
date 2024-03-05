// Vladimir Lihatchov 322017252
#pragma once
#include <string>
#include "GenericDB.h"
#include "CoursesDB.h"

using namespace std;

class Student
{
private:
    char *name;
    int age;
    string course;

public:
    Student() : name(nullptr), age(0), course(""){};
    Student(const char *studentName, int studentAge, string studentCourse) : age(studentAge), course(studentCourse)
    {
        name = strdup(studentName);
    }
    // copy
    Student(const Student &other);
    // Assignment operator
    Student &operator=(const Student &other);
    char *getName() { return name; }
    string getAll();
    ~Student() { free(name); }
};

class StudentDB : public GenericDB<Student>
{
private:
public:
    StudentDB() : GenericDB<Student>(){};
    Result enrollStudent(const Student &newStudent);
    ~StudentDB(){};
};
