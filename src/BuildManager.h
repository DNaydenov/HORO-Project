#pragma once
#include <iostream>
#include <string>

#include "FileManager.h"
#include "HoroBuilder.h"

using namespace std;

class BuildManager {
 private:
  DanceBuilder* builder;
  vector<string> names;

  vector<string> loadDataFromFile(string fileName);

 public:
  BuildManager(string fileName);
  ~BuildManager() = default;

  void  constructDanceFormation(string fileName);
  Dance *getConstruction();
};
