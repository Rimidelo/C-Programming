
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Enclosure.hpp"
#include "ZooKeeper.hpp"

ZooKeeper::ZooKeeper(const string &_name)
{
    name = _name;
    assignedEnclosures = nullptr;
    numOfEnclosuresOfkeeper = 0;
}

Result ZooKeeper::AssignToEnclosure(Enclosure *enclosure)
{
    if (enclosure == NULL)
    {
        return Fail;
    }
    for (int i = 0; i < numOfEnclosuresOfkeeper; i++)
    {
        if (assignedEnclosures[i] == enclosure)
        {
            cout << "ANIMAL ALREADY EXISTS IN THE ENCLOSURE";
            return Fail;
        }
    }
    // Resize the array to accommodate the new enclosure
    Enclosure **newAssignedEnclosures = new Enclosure *[numOfEnclosuresOfkeeper + 1];
    if (newAssignedEnclosures == nullptr)
    {
        cout << "Failed to allocate memory for assigned enclosures." << endl;
        return Fail;
    }

    // Copy existing enclosures to the new array
    for (int i = 0; i < numOfEnclosuresOfkeeper; ++i)
    {
        newAssignedEnclosures[i] = assignedEnclosures[i];
    }

    // Add the new enclosure
    if (enclosure->assignedZooKeeper == nullptr)
    {
        enclosure->assignedZooKeeper  = this;
        cout << "Zookeeper was assaigned successfully\n";
    }
    else{
        cout << "This Enclosure Alredy Has a Zookeeper\n";
    }
    newAssignedEnclosures[numOfEnclosuresOfkeeper] = enclosure;
    numOfEnclosuresOfkeeper++;

    // Delete the old array
    delete[] assignedEnclosures;

    // Update the animal_list pointer to point to the new array
    assignedEnclosures = newAssignedEnclosures;

    return Success;
}

ZooKeeper::~ZooKeeper()
{
    delete[] assignedEnclosures;
}