#pragma once
#include <iostream>
#include <cstring>
#include <unordered_map>
#include <iterator>
#include "Dancer.h"
using namespace std;

class Horo {
  unordered_map<string, Dancer *> dancers;

  bool isDancerExist(const string &name);

  bool isNextToEachOther(const string &firstName, const string &secondName);

 public:
  void release(const string &name, char side);

  void grab(const string &name, char side);

  void info(const string &name);

  void print() const;

  bool add(const string &name, const string &left = "Undefined", const string &right = "Undefined");

  vector<string> getNames();
};
