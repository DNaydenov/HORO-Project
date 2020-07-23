#include "Dance.h"

bool Dance::isExistDancerWithName(const std::string &name) {
  return !(dancers.find(name) == dancers.end());
}

bool Dance::isExistDancerWithName(const std::vector<std::string> &names) {
  for(const std::string &name : names) {
    if(!isExistDancerWithName(name)) {
      return false;
    }
  }
  return true;
}

bool Dance::areDancersAdjacent(const std::string &left, const std::string &right) {
  if(!isExistDancerWithName({left, right})) {
    return false;
  }
  return ((dancers[left]->getDancerInRight() == dancers[right]) && (dancers[right]->getDancerInLeft() == dancers[left]));
}

bool Dance::areDancersAdjacent(const std::vector<std::string> &names) {
  size_t i;
  for(i=0; i < names.size()-1; i++) {
   if(!isExistDancerWithName(names[i])) {
     return false;
   }
   else if(!areDancersAdjacent(names[i],names[i+1])) {
     return false;
   }
 }
 return true;
}


size_t Dance::getNumberOfDancers() const {
  return dancers.size();
}

std::vector<std::string> Dance::getNames() {
  std::vector<std::string> people;
  if (dancers.empty()) {
    return people;
  }
  Dancer *start = dancers.begin()->second;
  Dancer *next = start;
  do {
    people.push_back(next->getName());
    next = next->getDancerInRight();
  } while (next != start);
  return people;
}


void Dance::release(const std::string &name, char side) {
  dancers[name]->release(side);
}

void Dance::grab(const std::string &name, char side) {
  dancers[name]->grab(side);
}

void Dance::info(const std::string &name) {
  dancers[name]->info();
}

void Dance::print() const {
  Dancer *start = dancers.begin()->second;
  Dancer *next = start;
  do {
    std::cout << next->getName() << std::endl;
    next = next->getDancerInRight();
  } while (next != start);
}

