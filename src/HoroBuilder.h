#pragma oncе
#include "DanceBuilder.h"
#include "Horo.h"

class HoroBuilder : public DanceBuilder {

 public:

  explicit HoroBuilder(const array<string,3> &initialNames);

  void addDancer(string newDancerName, string leftDancerName, string rightDancerName) override;

};
