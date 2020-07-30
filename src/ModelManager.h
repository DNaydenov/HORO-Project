#pragma once
#include <map>

#include "BuildManager.h"
#include "FileManager.h"

using DanceFunctionPtr = void (Dance::*)(const vector<string> &);

class ModelManager {
 private:
  map<string, DanceFunctionPtr> commandsMap;

  string filename;
  Dance *dance{};

  void initialMapping();

 public:
  explicit ModelManager(string file);

  void setFilename(const string &file);

  void buildDance();
  void saveDataInFile() const;
  void executeCommand(const string &command,
                      const vector<string> &arguments = {});
};
