#include "Horo.h"

bool Horo::isDancerExist(const string &dancer_name) {
  return !(dancers.find(dancer_name) == dancers.end());
}

bool Horo::isNextToEachOther(const string &firstName,
                             const string &secondName) {
  return (dancers[firstName]->getDancerInRight() == dancers[secondName]);
}

void Horo::release(const string &name, char side) {
  dancers[name]->release(side);
}

void Horo::grab(const string &name, char side) { dancers[name]->grab(side); }

void Horo::info(const string &name) { dancers[name]->info(); }

void Horo::print() const {
  if (dancers.empty()) {
    return;
  }
  Dancer *start = dancers.begin()->second;
  Dancer *next = start;
  do {
    cout << next->getName() << endl;
    next = next->getDancerInRight();
  } while (next != start);
}

bool Horo::add(const string &name, const string &left, const string &right) {
  if (right == "Undefined") {
    if (left == "Undefined") {
      if (dancers.empty()) {
        Dancer *newDancer = new Dancer(name);
        dancers[name] = newDancer;
        newDancer->setDancersInBothSides(newDancer, newDancer);
        return true;
      } else {
        return false;
      }
    } else {
      if (dancers.size() == 1) {
        Dancer *newDancer = new Dancer(name);
        dancers[name] = newDancer;
        newDancer->setDancersInBothSides(dancers[left], dancers[left]);
        dancers[left]->setDancerInRight(newDancer);
        return true;
      } else {
        return false;
      }
    }
  } else {
    if (left == "Undefined") {
      return false;
    } else {
      if (isDancerExist(name) || !isNextToEachOther(left, right)) {
        return false;
      } else {
        Dancer *newDancer = new Dancer(name);
        dancers[name] = newDancer;
        newDancer->setDancersInBothSides(dancers[left], dancers[right]);
        dancers[left]->setDancerInRight(newDancer);
        dancers[right]->setDancerInLeft(newDancer);
        return true;
      }
    }
  }

  return true;
}

vector<string> Horo::getNames() {
  vector<string> people(dancers.size());
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
