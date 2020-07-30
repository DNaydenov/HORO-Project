#pragma once
#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Dancer {
  std::string dancerName = "Undefined";
  Dancer *dancerInLeft = nullptr;
  Dancer *dancerInRight = nullptr;
  bool holdDancerInLeft = false;
  bool holdDancerInRight = false;

 public:

  explicit Dancer(const std::string &name);
  Dancer(const std::string &name, Dancer *left, Dancer *right);
  Dancer(const Dancer &other);

  std::string getName() const;
  Dancer *getDancerInLeft() const;
  Dancer *getDancerInRight() const;

  void setDancerInLeft(Dancer *left, bool grabFlag = true);
  void setDancerInRight(Dancer *right, bool grabFlag = true);
  void setDancersInBothSides(Dancer *left = nullptr, Dancer *right = nullptr, char side = 'b');

  bool isHoldDancerInLeft() const;
  bool isHoldDancerInRight() const;

  void release(char side);
  void grab(char side);
  void info() const;
};