#pragma once
#include <iostream>
#include <string>
using namespace std;

class Dancer {
  string dancerName = "Undefined";
  Dancer *dancerInLeft = nullptr;
  Dancer *dancerInRight = nullptr;
  bool holdDancerInLeft = false;
  bool holdDancerInRight = false;

 public:

  explicit Dancer(const string &name);
  Dancer(const string &name, Dancer *left, Dancer *right);

  string getName() const;

  Dancer *getDancerInLeft() const;

  Dancer *getDancerInRight() const;

  void setDancerInLeft(Dancer *left, bool grabFlag = true);

  void setDancerInRight(Dancer *right, bool grabFlag = true);

  void setDancersInBothSides(Dancer *left = nullptr,
                             Dancer *right = nullptr,
                             bool grabFlagLeft = true,
                             bool grabFlagRight = true);

  bool isHoldDancerInLeft() const;

  bool isHoldDancerInRight() const;

  void release(char side);

  void grab(char side);

  void info() const;
};