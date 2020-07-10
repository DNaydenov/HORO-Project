#include "model.h"

Model::Model(Horo dance, FileManager file) : dance(dance), file(file)
{
}

Model::~Model()
{
}

void Model::saveDataInFile(string fileName)
{
    FileManager save(file);
    vector<string> dancers = dance.getNames();
    for (int i = 0; i <= dancers.size(); i++)
    {
        save.saveDataInFile(dancers[i]);
    }
}
