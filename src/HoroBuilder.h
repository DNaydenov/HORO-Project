#pragma once
#include <iostream>

#include "DanceBuilder.h"

class HoroBuilder : public DanceBuilder {
 public:
  HoroBuilder(string name1, string name2, string name3);
  ~HoroBuilder() = default;

  void addDancer(string name, string left, string right);

  Dance* getConstruction();

 private:
};
