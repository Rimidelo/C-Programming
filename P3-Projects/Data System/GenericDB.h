// Vladimir Lihatchov 322017252
#pragma once
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>


using namespace std;

enum Result {
    Success,
    Fail
};

// generic database template
template <class T>
class GenericDB
{
private:
    vector<T> records ;
public :
    GenericDB(){};
    Result insert(const T &record);
    Result remove(const char *name);
    Result update(T record);
    T query(const char *name);
    ~GenericDB(){};
};

template <class T>
Result GenericDB<T>::insert(const T &record)
{
    records.push_back(record);
    return Success;
};

template <class T>
Result GenericDB<T>::remove(const char *name)
{
    for (int i = 0; i < records.size(); i++)
    {
        if (strcmp(records.at(i).getName(),name)== 0)
        {
            records.erase(records.begin()+i);
            return Success;
        }
    }
    return Fail;
};

template <class T>
Result GenericDB<T>::update(T record){
    for (int i = 0; i < records.size(); i++)
    {
        if (strcmp(records.at(i).getName(),record.getName()) == 0)
        {
            records.at(i) = record;
            return Success;
        }
    }


    return Fail;
}

template <class T>
T GenericDB<T>::query(const char* name){
    for (int i = 0; i < records.size(); i++)
    {
        if (strcmp(records.at(i).getName(),name) == 0)
        {
            return records.at(i);
        }
    }
    return T();
};