// Vladimir Lihatchov 322017252
#pragma once
#include "CommandProcessor.h"

class OutputManager
{
private:
    string filename;

public:
    OutputManager(string _filename) : filename(_filename){};
    void writeOutput(string &output);
};

void OutputManager::writeOutput(string &output)
{
    ofstream outputFile(filename, std::ios_base::app);
    if (!outputFile.is_open())
    {
        std::cerr << "Failed to open the output file." << std::endl;
        return;
    }

    outputFile << output; 
};