#include "model.h"

Model::Model(Horo dance, FileManager file) : dance(dance), file(file) {}

Model::~Model() {}

void Model::saveDataInFile(string fileName) {
  file.saveDataInFile(dance.getNames());
}
