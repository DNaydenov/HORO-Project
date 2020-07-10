#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class FileManager {
 private:
  string fileName;

 public:
  FileManager(string file);
  FileManager();
  ~FileManager();

  string getFileName() const;
  void setFileName(string file);

  void loadDataFromFile();
  void saveDataInFile(vector<string> text);
};