#pragma once
#include "FileManager.h"
#include "Horo.h"
#include "string"

class Model {
 private:
  /* data */
  Horo dance;
  FileManager file;

 public:
  Model(Horo dance, string fileName);
  ~Model() = default;

  void buildDance(string fileName);
  void saveDataInFile();
  void executeCommand(string comaandn);
};