#pragma once
#include "Horo.h"
#include "FileManager.h"
#include "string"

class Model
{
private:
    /* data */
    Horo dance;
    FileManager file;

public:
    Model(Horo dance, FileManager file);
    ~Model();

    void buildDance(string fileName);
    void saveDataInFile(string fileName);
    void executeCommand(string comaandn);
};