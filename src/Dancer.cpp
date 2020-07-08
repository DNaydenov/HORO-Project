#include "Dancer.h"

Dancer::Dancer(const string &name)
{
  dancerName = name;
}

Dancer::Dancer(const string &name, Dancer *left, Dancer *right) {
  dancerName = name;
  dancerInLeft = left;
  dancerInRight = right;
}

string Dancer::getName() const {
  return dancerName;
}

Dancer *Dancer::getDancerInLeft() const {
  return dancerInLeft;
}

Dancer *Dancer::getDancerInRight() const {
  return dancerInRight;
}

void Dancer::setDancerInLeft(Dancer *left, bool grabFlag) {
  dancerInLeft = left;
  if (grabFlag) { holdDancerInLeft = true; }
}

void Dancer::setDancerInRight(Dancer *right, bool grabFlag) {
  dancerInRight = right;
  if (grabFlag) { holdDancerInRight = true; }
}

void Dancer::setDancersInBothSides(Dancer *left, Dancer *right, bool grabFlagLeft, bool grabFlagRight) {
  if (!right) {
    right = left;
  }
  setDancerInLeft(left, grabFlagLeft);
  setDancerInRight(right, grabFlagRight);
}

bool Dancer::isHoldDancerInLeft() const {
  return holdDancerInLeft;
}

bool Dancer::isHoldDancerInRight() const {
  return holdDancerInRight;
}

void Dancer::release(char side) {
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

void Dancer::grab(char side) {
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
  cout << dancerInLeft->getName() << " ";
  if (holdDancerInLeft) { cout << "<"; }
  cout << "---";
  if (dancerInLeft->holdDancerInRight) { cout << ">"; }
  cout << " " << getName() << " ";
  if (dancerInRight->holdDancerInLeft) { cout << "<"; }
  cout << "---";
  if (holdDancerInRight) { cout << ">"; }
  cout << " " << dancerInRight->getName() << " ";
}