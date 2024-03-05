// Vladimir Lihatchov 322017252
#pragma once
#include "GenericDB.h"

using namespace std;

class Course
{
private:
    char *title;
    string code;
    string instructor;

public:
    Course() : title(strdup("")), code(""), instructor(""){};
    Course(const char *courseTitle, string courseCode, string _instructor) : code(courseCode), instructor(_instructor)
    {title = strdup(courseTitle);}
    // Copy constructor
    Course(const Course &other);
    // Assignment operator
    Course &operator=(const Course &other);
    const char* getName() { return code.c_str(); }
    string getAll();
    
    ~Course(){free(title);}
};




class CourseDB : public GenericDB<Course>
{
private:
public:
    CourseDB() : GenericDB<Course>() {};
    void assignInstructor(const Course &course);
    ~CourseDB(){};
};

