//#include <gtest/gtest.h>
#include "model.h"
int main() {
  /* testing::InitGoogleTest();
   RUN_ALL_TESTS();*/
  /*Horo horo("Miro", "mitko", "nqkoi drug");
  Dance* pHoro = new Horo("Miro", "mitko", "nqkoi drug");*/
  // dynamic_cast<Dance*>(&horo)
  // HoroBuilder construction("Miro", "mitko", "nqkoi drug");
  // BuildManager bm("dancers.txt");

  Model model;
  model.buildDance("dancers.txt");
  model.dance->print();
  model.dance->add("Nasko", "Pesho", "Gosho");
  
  model.saveDataInFile("dancers.txt");
  return 0;
}
