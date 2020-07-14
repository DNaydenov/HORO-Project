#include <iostream>

#include "Horo.h"
#include "model.h"

int main() {
  Horo H;
  H.add("Ivan");
  H.add("Gosho", "Ivan");
  H.add("Pesho", "Ivan", "Gosho");
  H.add("Dragan", "Gosho", "Ivan");

  Model M(H, "dancers.txt");
  M.saveDataInFile();

  H.print();

  return 0;
}
