#pragma once
#include "BuildManager.h"
#include "FileManager.h"

class ModelManager {

 public:
  string filename;
  Dance *dance{};

 public:

  explicit ModelManager(const string &file);

  void setFilename(const string &file);

  void buildDance();
  void saveDataInFile() const;
  void executeCommand(vector<string> command);
};