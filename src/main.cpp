//#include <gtest/gtest.h>
#include "CommandParser.h"
#include "ModelManager.h"
void printH(int a) { cout << "hello"; }
int main() {
  // testing::InitGoogleTest();
  // RUN_ALL_TESTS();


  ModelManager M("dancers.txt");
  M.buildDance();
  M.dance->print();
  cout << endl;

  // Ivan - Pesho - Nasko - Gosho - Dragan
  (dynamic_cast<Horo*>(M.dance))->release("Ivan", 'r');
  (dynamic_cast<Horo*>(M.dance))->release("Pesho", 'l');
  (dynamic_cast<Horo*>(M.dance))->release("Pesho", 'r');
  (dynamic_cast<Horo*>(M.dance))->release("Nasko", 'l');
  (dynamic_cast<Horo*>(M.dance))->release("Nasko", 'r');
  (dynamic_cast<Horo*>(M.dance))->release("Gosho", 'l');
  (dynamic_cast<Horo*>(M.dance))->release("Gosho", 'r');
  (dynamic_cast<Horo*>(M.dance))->release("Dragan", 'l');
  M.dance->swap("Nasko", "Gosho");
  M.dance->swap("Gosho", "Pesho");
  for (auto name : M.dance->getNames()) {
    M.dance->info(name);
  }
  M.dance->print();

  return 0;
}
