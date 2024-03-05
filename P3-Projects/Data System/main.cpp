#include <iostream>
#include <fstream>
#include "CommandProcessor.h"
#include "OutputManager.h"

int main() {
    // Initialize the database instances for students and courses
    StudentDB studentDb;
    CourseDB courseDb;

    // Initialize the CommandProcessor with the database instances
    CommandProcessor commandProcessor(&studentDb, &courseDb);

    // Initialize the OutputManager
    OutputManager outputManager("output.txt");

    // Open the input file
    std::ifstream inputFile("input.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Failed to open input.txt" << std::endl;
        return 1;
    }

    // Process each line in the input file
    std::string command;
    while (getline(inputFile, command)) {
        // Process the command and capture the output
        std::string result = commandProcessor.processCommand(command);

        // Write the result to the output file
        outputManager.writeOutput(result);
    }

    inputFile.close();
    return 0;
}