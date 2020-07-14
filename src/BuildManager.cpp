#include "BuildManager.h"

void BuildManager::constructDanceFormation(string fileName) {
  loadDataFromFile(fileName);
  this->builder = new HoroBuilder(names[0], names[1], names[2]);
  for (int  i = 3; i < names.size(); i++) {
    builder->addDancer(names[i], names[i - 1], names[0]);
  }
}

Dance* BuildManager::getConstruction() { return builder->getConstruction(); }

vector<string> BuildManager::loadDataFromFile(string fileName) {
  FileManager temp(fileName);
  names = temp.loadDataFromFile();

  //TOOD
  return names;
}

BuildManager::BuildManager(string fileName) {
  constructDanceFormation(fileName);
}
