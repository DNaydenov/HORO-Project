#pragma once
#include <iostream>
#include <string>
#include "FileManager.h"
#include "HoroBuilder.h"

using namespace std;

class BuildManager {

  string filename = "";
  DanceBuilder *danceBuilder{};
  vector<string> names{};

  void loadDataFromFile();

 public:
  explicit BuildManager(const string &file);

  void setFilename(const string &file);

  void constructDanceFormation();
  Dance *getConstruction();
};
