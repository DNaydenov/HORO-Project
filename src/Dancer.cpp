#include "Dancer.h"

Dancer::Dancer(const std::string &name)
{
  dancerName = name;
}

Dancer::Dancer(const std::string &name, Dancer *left, Dancer *right) {
  dancerName = name;
  setDancersInBothSides(left,right);
}


std::string Dancer::getName() const {
  return dancerName;
}

Dancer *Dancer::getDancerInLeft() const {
  return dancerInLeft;
}

Dancer *Dancer::getDancerInRight() const {
  return dancerInRight;
}


void Dancer::setDancerInLeft(Dancer *left, bool grabLeft) {
  dancerInLeft = left;
  if (grabLeft) { holdDancerInLeft = true; }
}

void Dancer::setDancerInRight(Dancer *right, bool grabRight) {
  dancerInRight = right;
  if (grabRight) { holdDancerInRight = true; }
}

void Dancer::setDancersInBothSides(Dancer *left, Dancer *right, bool grabLeft, bool grabRight) {
  if (!right) {
    right = left;
  }
  setDancerInLeft(left, grabLeft);
  setDancerInRight(right, grabRight);
}


bool Dancer::isHoldDancerInLeft() const {
  return holdDancerInLeft;
}

bool Dancer::isHoldDancerInRight() const {
  return holdDancerInRight;
}

void Dancer::release(const char side) {
  switch (side) {
    case 'l' : holdDancerInLeft = false;
      break;
    case 'r' : holdDancerInRight = false;
      break;
    case 'b' : {
      holdDancerInLeft = false;
      holdDancerInRight = false;
    }
      break;
    default :; //return error message
  }
}

void Dancer::grab(const char side) {
  switch (side) {
    case 'l' : holdDancerInLeft = true;
      break;
    case 'r' : holdDancerInRight = true;
      break;
    case 'b' : {
      holdDancerInLeft = true;
      holdDancerInRight = true;
    }
      break;
    default :; //return error message
  }
}

void Dancer::info() const{
  std::cout << dancerInLeft->getName() << " ";
  if (holdDancerInLeft) { std::cout << "<"; }
  std::cout << "---";
  if (dancerInLeft->holdDancerInRight) { std::cout << ">"; }
  std::cout << " " << getName() << " ";
  if (dancerInRight->holdDancerInLeft) { std::cout << "<"; }
  std::cout << "---";
  if (holdDancerInRight) { std::cout << ">"; }
  std::cout << " " << dancerInRight->getName() << std::endl;
}