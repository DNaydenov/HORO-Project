#include "Dancer.h"

Dancer::Dancer(const std::string &name) { dancerName = name; }

Dancer::Dancer(const std::string &name, Dancer *left, Dancer *right) {
  dancerName = name;
  setDancersInBothSides(left, right);
}

Dancer::Dancer(const Dancer &other)
    : dancerName(other.getName()),
      dancerInLeft(other.getDancerInLeft()),
      dancerInRight(other.getDancerInRight()),
      holdDancerInLeft(other.isHoldDancerInLeft()),
      holdDancerInRight(other.isHoldDancerInRight()) {}


std::string Dancer::getName() const { return dancerName; }

Dancer *Dancer::getDancerInLeft() const { return dancerInLeft; }

Dancer *Dancer::getDancerInRight() const { return dancerInRight; }

bool Dancer::isHoldDancerInLeft() const { return holdDancerInLeft; }

bool Dancer::isHoldDancerInRight() const { return holdDancerInRight; }


void Dancer::setDancerInLeft(Dancer *left, bool grabLeft) {
  dancerInLeft = left;
  holdDancerInLeft = grabLeft;
}

void Dancer::setDancerInRight(Dancer *right, bool grabRight) {
  dancerInRight = right;
  holdDancerInRight = grabRight;
}

void Dancer::setDancersInBothSides(Dancer *left, Dancer *right, char side) {

  setDancerInLeft(left);
  setDancerInRight(right);

  switch (side) {
    case 'l':
      if(left) grab('l'); break;
    case 'r':
      if(right) grab('r'); break;
    case 'b':
      if(left && right) grab('b'); break;
    default: throw runtime_error("The parameter 'side' is incorrect.");
  }
}


void Dancer::release(const char side) {
  switch (side) {
    case 'l':
      holdDancerInLeft = false;
      break;
    case 'r':
      holdDancerInRight = false;
      break;
    case 'b': {
      holdDancerInLeft = false;
      holdDancerInRight = false;
    } break;
    default: throw runtime_error("The parameter 'side' is incorrect.");
  }
}

void Dancer::grab(const char side) {
  switch (side) {
    case 'l':
      holdDancerInLeft = true;
      break;
    case 'r':
      holdDancerInRight = true;
      break;
    case 'b': {
      holdDancerInLeft = true;
      holdDancerInRight = true;
    } break;
    default: throw runtime_error("The parameter 'side' is incorrect.");
  }
}

void Dancer::info() const {
  std::cout << dancerInLeft->getName() << " ";
  if (holdDancerInLeft) { std::cout << "<"; }
  std::cout << "---";
  if (dancerInLeft->holdDancerInRight) {  std::cout << ">"; }
  std::cout << " " << getName() << " ";
  if (dancerInRight->holdDancerInLeft) { std::cout << "<"; }
  std::cout << "---";
  if (holdDancerInRight) {  std::cout << ">"; }
  std::cout << " " << dancerInRight->getName() << std::endl;
}