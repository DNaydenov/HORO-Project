#pragma once
#include <iostream>
#include <string>

#include "DanceBuilder.h"
#include "FileManager.h"

using namespace std;

class BuildManager {
 private:
  FileManager file;
  DanceBuilder* builder;

 public:
  BuildManager();
  ~BuildManager();

  void constructDanceFormation(string fileName);
  void loadDataFromFile(string fileName);
  void finishConstruction();
};
