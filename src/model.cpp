#include "model.h"

Model::Model(Horo dance, string fileName) : dance(dance), file(fileName) {}

void Model::saveDataInFile() {
  file.saveDataInFile(dance.getNames());
}
