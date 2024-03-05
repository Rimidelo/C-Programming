#include "StudentDB.h"


// copy constructor
Student::Student(const Student &other) : age(other.age), course(other.course)
{
    name = strdup(other.name);
}
//= operator
Student &Student::operator=(const Student &other)
{
    if (this != &other)
    {
        age = other.age;
        course = other.course;
        free(name);
        name = strdup(other.name);
    }
    return *this;
}

string Student::getAll()
{
    string result;
    return result = string(name) + ", " + to_string(age) + ", " + course;
};

///////////////////students db funcs
// Implementation of enrollStudent function
Result StudentDB::enrollStudent(const Student &newStudent)
{
    return insert(newStudent);
}