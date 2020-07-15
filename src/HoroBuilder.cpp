#include "HoroBuilder.h"

HoroBuilder::HoroBuilder(const array<string,3> &initialNames) {
  construction = dynamic_cast<Dance *>(new Horo(initialNames));
}

void HoroBuilder::addDancer(string newDancerName, string leftDancerName, string rightDancerName) {
  construction->add(newDancerName, leftDancerName, rightDancerName);
}
