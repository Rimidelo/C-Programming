// Vladimir Lihatchov 322017252
#include <iostream>
#include <cstring>
#include <stdlib.h>
#include "Zoo.hpp"

int main()
{

    using namespace std;

    int option;
    string _name, species;

    Zoo *Zoo1 = new Zoo;

    do
    {
        cout << "\nWelcome to the Zoo!\n";
        cout << "Please select an option:\n";
        cout << "1. Add an Animal\n";
        cout << "2. Remove an Animal\n";
        cout << "3. Display all Animals\n";
        cout << "4. Add a Zookeeper\n";
        cout << "5. Exit\n";
        cin >> option;
        cout << "\n";

        switch (option)
        {
        case 1:
            Zoo1->AddAnimal();
            break;
        case 2:
            Zoo1->RemoveAnimal();
            break;
        case 3:
            Zoo1->DispalyAnimals();
            break;
        case 4:
            cout << "What is the name of the ZooKeeper?: ";
            cin >> _name;
            cout << "Which species enclosure he keeps?: ";
            cin >> species;
            Zoo1->assignZooKeeper(Zoo1->CreateZookeeper(_name),Zoo1->FindEnclosure(species));
            break;
        case 5:
            break;
        default:
            cout << "Invalid input, choose from the menu below...\n";
            break;
        }
    } while (option != 5);

    delete Zoo1;
    return 1;
}