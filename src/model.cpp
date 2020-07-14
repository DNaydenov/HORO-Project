#include "model.h"

void Model::buildDance(string fileName) {
  BuildManager manager(fileName);
  dance = dynamic_cast<Horo *>(manager.getConstruction());
}

void Model::saveDataInFile(string fileName) {
  FileManager file(fileName);
  file.saveDataInFile(dance->getNames());
}
