#pragma once
#include <fstream>

#include <vector>

using namespace std;

class FileManager {

  string filename;

 public:
  explicit FileManager(string filename);

  const string & getFilename() const;
  void setFilename(const string &filename);

  void loadDataFromFile(vector<string> &names);
  void saveDataInFile(const vector<string> &names);
};