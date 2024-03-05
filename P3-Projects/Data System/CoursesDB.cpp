#include "StudentDB.h"

// copy constructor
Course::Course(const Course &other) : code(other.code), instructor(other.instructor)
{
    title = strdup(other.title);
}


//= operator
Course &Course::operator=(const Course &other)
{
    if (this != &other)
    {
        code = other.code;
        instructor = other.instructor;
        free(title);
        title = strdup(other.title);
    }
    return *this;
}

string Course::getAll(){
    string result;
    return result  = string(title) + ", " + code + ", "+ instructor;
}

/////// coursesDB

