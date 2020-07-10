
#include <fstream>
#include <iostream>

using namespace std;

class FileManager
{
private:
    string fileName;

public:
    FileManager(string file);
    FileManager();
    ~FileManager();
    void setFileName(string file);
    void loadDataFromFile();
    void saveDataInFile(string name);
};