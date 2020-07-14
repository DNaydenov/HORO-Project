#include "HoroBuilder.h"

HoroBuilder::HoroBuilder(string name1, string name2, string name3) {
  construction = new Horo(name1, name2, name3);
}

void HoroBuilder::addDancer(string name, string left, string right) {
  construction->add(name, left, right);
}
