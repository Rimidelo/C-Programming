// Vladimir Lihatchov 322017252
#pragma once
#include <stdlib.h>
#include <cstring>
#include <string>
#include <sstream>
#include "StudentDB.h"
#include "CoursesDB.h"


using namespace std;

// enum Result {
//     Success,
//     Fail
// };

enum Action
{
    INSERT,
    DELETE,
    UPDATE,
    QUERY,
    Comment
};



class CommandProcessor
{
private:
    StudentDB* studentDb;
    CourseDB* courseDb;

public:
    // Accept pointers in the constructor
    CommandProcessor(StudentDB* _studentDb, CourseDB* _courseDb) : studentDb(_studentDb), courseDb(_courseDb) {}
    string processCommand(string line);
    ~CommandProcessor(){};
};



