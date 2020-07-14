#pragma once
#include <iostream>

#include "Horo.h"

using namespace std;

class DanceBuilder {
 private:
  Horo construction;

 public:
  DanceBuilder(Horo constrution);
  ~DanceBuilder() = default;

  virtual void addDancer(string name) = 0;
  ;
  virtual Horo getConstruction() = 0;
};
