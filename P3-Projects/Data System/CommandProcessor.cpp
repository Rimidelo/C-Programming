#include "CommandProcessor.h"
Action getCommand(string comm)
{
    if (comm == "INSERT")
        return INSERT;
    else if (comm == "DELETE")
        return DELETE;
    else if (comm == "UPDATE")
        return UPDATE;
    else if (comm == "QUERY")
        return QUERY;
    return Comment;
}

string CommandProcessor::processCommand(string line)
{
    istringstream iss(line);
    string command;
    iss >> command;  // parse the stream into the first word
    string nextWord; // second word when needed
    Action cmd = getCommand(command);
    string name, age, major;
    string title, code, istructorName;
    string buff;
    string result;
    Result boolResult;

    switch (cmd)
    {
    case INSERT:
    {
        iss >> nextWord;
        if (nextWord == "STUDENT")
        {
            iss >> ws; // consume leading whitespaces
            getline(iss, name, ',');
            iss >> ws; //
            getline(iss, age, ',');
            iss >> ws; //
            getline(iss, major);

            Student student(name.c_str(), stoi(age), major);
            boolResult = studentDb->enrollStudent(student);
            if (boolResult == Success)
            {
                return result = "Success: Student \"" + name + ", " + age + ", " + major + "\" added.\n";
            }
            else
            {
                return result = "Error: Invalid command format.\n";
            }
        }
        else if (nextWord == "COURSE")
        {
            iss >> ws; // consume leading whitespaces
            getline(iss, title, ',');
            iss >> ws; //
            getline(iss, code, ',');
            iss >> ws; //
            getline(iss, istructorName);

            Course course(title.c_str(), code, istructorName);
            boolResult = courseDb->insert(course);
            if (boolResult == Success)
            {
                return result = "Success: Course \"" + title + ", " + code + ", " + istructorName + "\" added.\n";
            }
            else
            {
                return result = "Error: Invalid command format.\n";
            }
        }
        break;
    }
    case QUERY:
    {
        iss >> nextWord;
        if (nextWord == "STUDENT")
        {
            getline(iss, buff, '=');
            iss >> ws;
            getline(iss, name);
            Student student = studentDb->query(name.c_str());
            if (student.getName() == nullptr)
            {

                return result = "Query Result: No Student found matching criteria.\n";
            }
            else
            {
                return result = "Query Result: " + student.getAll() + ".\n";
            }
        }
        else if (nextWord == "COURSE")
        {
            getline(iss, buff, '=');
            iss >> ws;
            getline(iss, code);
            Course course = courseDb->query(code.c_str());
            if (strcmp(course.getName(), "") == 0)
            {
                return result = "Query Result: No Course found matching criteria.\n";
            }
            else
            {
                return result = "Query Result: " + course.getAll() + ".\n";
            }
        }
        break;
    }
    case DELETE:
    {
        iss >> nextWord;
        if (nextWord == "STUDENT")
        {
            iss >> ws;
            getline(iss, name);
            Student student = studentDb->query(name.c_str());
            boolResult = studentDb->remove(name.c_str());
            if (boolResult == Success)
            {
                return result = "Success: Student \"" + student.getAll() + "\" deleted.\n";
            }
            else
            {
                return result = "Error: Invalid command format\n";
            }
        }
        else if (nextWord == "COURSE")
        {
            iss >> ws;
            getline(iss, code);
            Course course = courseDb->query(code.c_str());
            boolResult = courseDb->remove(code.c_str());
            if (boolResult == Success)
            {
                return result = "Success: Course \"" + course.getAll() + "\" deleted.\n";
            }
            else
            {
                return result = "Error: Invalid command format\n";
            }
        }
        break;
    }
    case UPDATE:
    {
        iss >> nextWord;
        if (nextWord == "STUDENT")
        {
            iss >> ws; // consume leading whitespaces
            getline(iss, name, ',');
            iss >> ws; //
            getline(iss, age, ',');
            iss >> ws; //
            getline(iss, major);

            Student student(name.c_str(), stoi(age), major);
            Student foundStudent = studentDb->query(name.c_str());
            boolResult = studentDb->update(student);
            if (boolResult == Success)
            {
                return result = "Success: Student \"" + foundStudent.getAll() + "\" updated to \"" + student.getAll() + "\".\n";
            }
            else
            {
                return result = "Query Result: No Student found matching criteria.\n";
            }
        }
        else if (nextWord == "COURSE")
        {
        }
        break;
    }
    default:
    {
        break;
    }
    }
    return result = "Error: Invalid command format\n";
};