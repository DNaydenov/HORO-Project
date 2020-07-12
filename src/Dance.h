#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Dancer.h"

class Dance {
 protected:
  unordered_map<string, Dancer*> dancers;

 public:

  bool isThereDancerWithName(const string &name);
  bool isThereDancerWithName(const vector<string> &names);

  bool areDancersAdjacent(const string &left, const string &right);
  bool areDancersAdjacent(const vector<string> &names);

  size_t getNumberOfDancers() const;
  vector<string> getNames();

  void release(const string &name, char side);
  void grab(const string &name, char side);
  void info(const string &name);
  void print() const;

  virtual void add(const string &dancer, const string &leftDancer, const string &rightDancer) = 0;
  virtual void remove(const string &name) = 0;
  virtual void swap(const string& first, const string& second) = 0;
};
