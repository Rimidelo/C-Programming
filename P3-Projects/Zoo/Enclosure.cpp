// Vladimir Lihatchov 322017252
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Enclosure.hpp"

Enclosure::Enclosure(string species) {
    this->species = species;
    numOfAnimals = 0;
    animal_list = nullptr;
    assignedZooKeeper  = nullptr;
}

Result Enclosure::AddAnimal(Animal *_animal)
{
    if (_animal == NULL)
    {
        return Fail;
    }
    for (int i = 0; i < numOfAnimals; i++)
    {
        if (animal_list[i] == _animal)
        {
            cout << "ANIMAL ALREADY EXISTS IN THE ENCLOSURE";
            return Fail;
        }
    }
    // Resize the array to accommodate the new animal
    Animal **newAnimalList = new Animal *[numOfAnimals + 1];
    if (newAnimalList == nullptr)
    {
        return Fail;
    }
    
    // Copy existing animals to the new array
    for (int i = 0; i < numOfAnimals; ++i)
    {
        newAnimalList[i] = animal_list[i];
    }

    // Add the new animal
    newAnimalList[numOfAnimals] = _animal;
    numOfAnimals++;

    // Delete the old array
    delete[] animal_list;

    // Update the animal_list pointer to point to the new array
    animal_list = newAnimalList;

    return Success;
}

Animal* Enclosure::FindAnimal(const string& name, const string& species) {
    for (int i = 0; i < numOfAnimals; i++) {
        // Use the getter functions to retrieve attributes
        const string& animalName = animal_list[i]->GetName();
        const string& animalSpecies = animal_list[i]->GetSpecies();

        // Check if the attributes match the provided values
        if (animalName == name && animalSpecies == species) {
            return animal_list[i]; // Return the pointer to the found animal
        }
    }
    cout << "ANIMAL WAS NOT FOUND\n";
    return nullptr; // Return nullptr if no matching animal is found
}

Result Enclosure::RemoveAnimal(Animal *_animal)
{
    if (_animal == NULL)
    {
        return Fail;
    }
    if (numOfAnimals == 0)
    {
        cout << "THERE ARE NO ANIMALS TO REMOVE";
        return Fail;
    }
    for (int i = 0; i < numOfAnimals; i++)
    {
        if (animal_list[i] == _animal)
        {
            delete animal_list[i];
            animal_list[i] = animal_list[numOfAnimals - 1];
            numOfAnimals--;

            return Success;
        }
    }
    cout << "ANIMAL WAS NOT FOUND\n";
    return Fail;
}

Result Enclosure::GetAnimals() const
{
    if (numOfAnimals == 0)
    {
        cout << "THERE ARE NO ANIMALS IN THE ENCLOSURE";
        return Fail;
    }
    cout << "Animals in the " << species << " enclosure: \n";
    for (int i = 0; i < numOfAnimals; i++)
    {
        animal_list[i]->DisplayDetails();
    }
    if (this->assignedZooKeeper != nullptr)
    {
        cout << "The Zookeeper of this enclosure is: "<< this->assignedZooKeeper->GetName() << "\n";
    }
    else{
        cout << "There is no zookeeper for this enclosure right now\n";
    }
    return Success;
}

Enclosure::~Enclosure()
{
    for (int i = 0; i < numOfAnimals; i++)
    {
        delete animal_list[i]; // the animals in the list
        
    }
    delete assignedZooKeeper;
    delete[] animal_list;
}
