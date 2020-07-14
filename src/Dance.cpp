#include "Dance.h"

bool Dance::isExistDancerWithName(const string &name) {
  return !(dancers.find(name) == dancers.end());
}

bool Dance::isExistDancerWithName(const vector<string> &names) {
  for(const string &name : names) {
    if(!isExistDancerWithName(name)) {
      return false;
    }
  }
  return true;
}

bool Dance::areDancersAdjacent(const string &left, const string &right) {
  return ((dancers[left]->getDancerInRight() == dancers[right]) && (dancers[right]->getDancerInLeft() == dancers[left]));
}

bool Dance::areDancersAdjacent(const vector<string> &names) {
  Dancer *start = dancers.begin()->second;
  Dancer *next = start;
  do {
    if(!areDancersAdjacent(next->getName(),next->getDancerInRight()->getName())) {
      return false;
    }
    next = next->getDancerInRight();
  } while (next != start);
  return true;
}


size_t Dance::getNumberOfDancers() const {
  return dancers.size();
}

vector<string> Dance::getNames() {
  vector<string> people;
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


void Dance::release(const string &name, char side) {
  dancers[name]->release(side);
}

void Dance::grab(const string &name, char side) {
  dancers[name]->grab(side);
}

void Dance::info(const string &name) {
  dancers[name]->info();
}

void Dance::print() const {
  Dancer *start = dancers.begin()->second;
  Dancer *next = start;
  do {
    cout << next->getName() << endl;
    next = next->getDancerInRight();
  } while (next != start);
}

