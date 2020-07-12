#include "Horo.h"

//TODO check the type of exceptions
//TODO add valid exception messages

Horo::Horo(const vector<string> &names) {
  add(names);
}

void Horo::add(const string &B, const string &A, const string &C) {

  if (dancers.empty()) {
    Dancer *middleDancer = new Dancer(B),
           *leftDancer = new Dancer(A),
           *rightDancer = new Dancer(C);

    middleDancer->setDancersInBothSides(leftDancer, rightDancer);
    leftDancer->setDancersInBothSides(rightDancer, middleDancer);
    rightDancer->setDancersInBothSides(middleDancer, leftDancer);

    dancers.insert({{A,leftDancer}, {B,middleDancer}, {C,rightDancer}});
  }
  else if (isThereDancerWithName(B)) {
    throw runtime_error("The dancer with name " + B + " already exists.");
  }
  else if (!isThereDancerWithName(A) || !isThereDancerWithName(C)) {
    if(!isThereDancerWithName(A)) {
      throw runtime_error("The dancer with name " + A + " does not exist.");
    }
    else {
      throw runtime_error("The dancer with name " + C + " does not exist.");
    }
  }
  else if (!areDancersAdjacent(A, C)) {
    throw runtime_error("The dancers with names " + A + " and " + C + " are not adjacent.");
  }
  else {
    Dancer *newDancer = new Dancer(B);

    newDancer->setDancersInBothSides(dancers[A], dancers[C]);
    dancers[A]->setDancerInRight(newDancer);
    dancers[C]->setDancerInLeft(newDancer);

    dancers.insert({{B,newDancer}});
  }
}

void Horo::add(const vector<string> &names) {
  if(names.size() < 3) {
    return;
  }
  else {
    add(names[1],names[0],names[2]);
    if(names.size() > 3) {
      for (int i = 3; i < names.size(); i++) {
        add(names[i], names[i - 1], names[0]);
      }
    }
  }
}

void Horo::remove(const string &A) {
  if (!isThereDancerWithName(A)) {
    throw runtime_error("");
  }
  if (dancers[A]->isHoldDancerInLeft() || dancers[A]->isHoldDancerInRight()) {
    throw runtime_error(A + " hold another dancer.");
  }
  else if (dancers[A]->getDancerInLeft()->isHoldDancerInRight()
      || dancers[A]->getDancerInRight()->isHoldDancerInLeft()) {
    throw runtime_error("Another dancer hold " + A + ".");
  }
  else {
    dancers[A]->getDancerInLeft()->setDancerInRight(dancers[A]->getDancerInRight());
    dancers[A]->getDancerInRight()->setDancerInLeft(dancers[A]->getDancerInLeft());
    dancers.erase(A);
    if (dancers.size() == 2) {
      //exit();
    }
  }
}

void Horo::swap(const string &A, const string &B) {
  if (!isThereDancerWithName(A) || !isThereDancerWithName(B)) {
    throw runtime_error("1");
  } else if (!areDancersAdjacent(A, B) && !areDancersAdjacent(B, A)) {
    throw runtime_error("2");
  }
  //...
}