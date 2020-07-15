//#include <gtest/gtest.h>
#include "ModelManager.h"
int main() {
  // testing::InitGoogleTest();
  // RUN_ALL_TESTS();

  ModelManager M("dancers.txt");
  M.buildDance();
  M.dance->print();

  return 0;
}
