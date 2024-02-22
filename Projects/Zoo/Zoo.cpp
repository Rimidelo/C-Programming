#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Enclosure.hpp"
#include "ZooKeeper.hpp"
#include "Zoo.hpp"

Zoo::Zoo()
{
    numOfEnclosures = 0;
    Enclosure_list = nullptr;
    // ZooKeeper_list = nullptr;
    // numOfZooKeepers = 0;
}

Result Zoo::AddAnimal()
{
    cout << "Please Enter An Animal: ";
    string name, species;
    int age;

    // Get input from the user
    cout << "Enter name: ";
    cin >> name;

    cout << "Enter species: ";
    cin >> species;

    cout << "Enter age: ";
    cin >> age;

    int flag = 0;
    // first we need to create or find an enclosure
    for (int i = 0; i < numOfEnclosures; i++) // find enclosure and put animal inside
    {
        if (Enclosure_list[i]->GetEnclosureSpecies() == species)
        {
            Animal *newAnimal = new Animal(name, species, age);
            if (newAnimal == nullptr)
            {
                delete newAnimal;
                return Fail;
            }
            Enclosure_list[i]->AddAnimal(newAnimal);
            flag = 1;
            cout << "Animal Added Successfully\n";
            return Success;
        }
    }
    if (numOfEnclosures == 0 || flag == 0)
    {
        // Resize the array to accommodate the new enclosure
        Enclosure **newEnclosureList = new Enclosure *[numOfEnclosures + 1];
        // Copy existing Enclosures to the new array
        for (int i = 0; i < numOfEnclosures; ++i)
        {
            newEnclosureList[i] = Enclosure_list[i];
        }

        // Add the new enclosure and add new animal to it
        Enclosure *newEnclosure = new Enclosure(species);
        if (newEnclosure == nullptr)
        {
            delete newEnclosure;
            return Fail;
        }
        Animal *newAnimal = new Animal(name, species, age);
        if (newAnimal == nullptr)
        {
            delete newAnimal;
            return Fail;
        }
        newEnclosure->AddAnimal(newAnimal);
        newEnclosureList[numOfEnclosures] = newEnclosure;
        numOfEnclosures++;

        // Delete the old array
        delete[] Enclosure_list;

        // Update the Enclosure_list pointer to point to the new array
        Enclosure_list = newEnclosureList;
        cout << "Animal And New Enclosure Added Successfully\n";
        return Success;
    }
    return Fail;
}

Result Zoo::RemoveAnimal()
{
    cout << "Please Enter An Animal: ";
    string name, species;
    // int age;

    // Get input from the user
    cout << "Enter name: ";
    cin >> name;

    cout << "Enter species: ";
    cin >> species;

    for (int i = 0; i < numOfEnclosures; i++)
    {
        // Search the enclosures
        Animal *foundAnimal = Enclosure_list[i]->FindAnimal(name, species);

        if (foundAnimal != nullptr)
        {
            // Remove the found animal from the enclosure
            Enclosure_list[i]->RemoveAnimal(foundAnimal);
            cout << "Animal removed successfully\n";
            if (Enclosure_list[i]->GetNumOfAnimals()==0)
            {
                cout << "All Animals have been removed and this enclosure is now closed\n";
                delete Enclosure_list[i];
                Enclosure_list[i] = Enclosure_list[numOfEnclosures - 1];
                numOfEnclosures--;
            }
            
            return Success;
        }
    }
    
    cout << "Animal not found in any enclosure\n";
    return Fail;
}

Result Zoo::DispalyAnimals()
{
    if (GetNumOfEnclosures() == 0)
    {
        cout << "THERE ARE NO ANIMALS" << endl;
        return Fail;
    }
    for (int i = 0; i < numOfEnclosures; i++)
    {
        Enclosure_list[i]->GetAnimals();
        cout << "\n";
    }
    return Success;
}

ZooKeeper* Zoo::CreateZookeeper(string _name){
    ZooKeeper *newZooKeeper = new ZooKeeper(_name);
    if (newZooKeeper == nullptr)
    {
        cout << "Not Enough Memory";
        delete newZooKeeper;
        return nullptr;
    }
    return newZooKeeper;
}

Enclosure* Zoo::FindEnclosure(const string& species){
    for (int i = 0; i < numOfEnclosures; i++) {
        // Use the getter functions to retrieve attributes
        const string& animalSpecies = Enclosure_list[i]->GetEnclosureSpecies();

        // Check if the attributes match the provided values
        if (animalSpecies == species) {
            return Enclosure_list[i]; // Return the pointer to the found animal
        }
    }
    cout << "Enclosure was not found\n";
    return nullptr; // Return nullptr if no matc
}

Result Zoo::assignZooKeeper(ZooKeeper *_ZooKeeper,Enclosure *Enclosure){
    _ZooKeeper->AssignToEnclosure(Enclosure);
    return Success;
}

Zoo::~Zoo()
{
    for (int i = 0; i < numOfEnclosures; i++)
    {
        delete Enclosure_list[i]; // the animals in the list
    }

    delete[] Enclosure_list;
}
