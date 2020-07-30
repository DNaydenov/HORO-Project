#include "ModelManager.h"

ModelManager::ModelManager(const string &file) : filename(file){}

void ModelManager::setFilename(const string &file) {
  filename = file;
}

void ModelManager::buildDance() {
  BuildManager manager(filename);
  manager.constructDanceFormation();
  dance = manager.getConstruction();
}

void ModelManager::saveDataInFile() const {
  FileManager fileManager(filename);
  fileManager.saveDataInFile(dance->getNames());
}

void ModelManager::executeCommand(vector<string> command) {
    
}
