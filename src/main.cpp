#include <iostream>
#include "Horo.h"

int main() {

  Horo H;
  H.add("Ivan");
  H.add("Gosho","Ivan");
  H.add("Pesho","Ivan","Gosho");
  H.add("Dragan","Gosho","Ivan");

  H.print();
  
  return 0;
}
