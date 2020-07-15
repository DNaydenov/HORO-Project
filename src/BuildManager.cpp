#include "BuildManager.h"

#include <utility>

BuildManager::BuildManager(const string &file) : filename(file) {}

void BuildManager::setFilename(const string &file) {
  filename = file;
}

void BuildManager::constructDanceFormation() {

  loadDataFromFile();

  HoroBuilder builder({names[0], names[1], names[2]});

  for (int i = 3; i < names.size(); i++) {
    builder.addDancer(names[i], names[i - 1], names[0]);
  }

  danceBuilder = dynamic_cast<DanceBuilder *>(&builder);
}

Dance * BuildManager::getConstruction() {
  return danceBuilder->getConstruction();
}

void BuildManager::loadDataFromFile() {
  FileManager fileManager(filename);
  fileManager.loadDataFromFile(names);
}