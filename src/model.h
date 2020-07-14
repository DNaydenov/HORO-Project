#pragma once
#include "BuildManager.h"
#include "FileManager.h"
#include "Horo.h"
#include "string"
class Model {
 private:
  /* data */

 public:
  Horo *dance = nullptr;
  ~Model() = default;

  void buildDance(string fileName);
  void saveDataInFile(string fileName);
  void executeCommand(string comaandn);
};