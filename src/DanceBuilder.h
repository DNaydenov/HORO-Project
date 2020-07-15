#pragma once
#include "Dance.h"
using namespace std;

class DanceBuilder {
 protected:
  Dance *construction{};

 public:

  virtual void addDancer(string name, string left, string right) = 0;

  Dance * getConstruction();
};
