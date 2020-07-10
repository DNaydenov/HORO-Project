#include <iostream>

#include "Horo.h"
#include "model.h"

int main() {
  Horo H;
  H.add("Ivan");
  H.add("Gosho", "Ivan");
  H.add("Pesho", "Ivan", "Gosho");
  H.add("Dragan", "Gosho", "Ivan");

  FileManager FM("dancers.txt");
  Model M(H, FM);
  M.saveDataInFile(FM.getFileName());

  H.print();

  return 0;
}
