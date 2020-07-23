#include "Horo.h"

void Horo::initialAdd(const array<string, 3> &initialNames) {
  Dancer *firstDancer = new Dancer(initialNames[0]),
         *secondDancer = new Dancer(initialNames[1]),
         *thirdDancer = new Dancer(initialNames[2]);

  firstDancer->setDancersInBothSides(thirdDancer, secondDancer);
  secondDancer->setDancersInBothSides(firstDancer, thirdDancer);
  thirdDancer->setDancersInBothSides(secondDancer, firstDancer);

  dancers.insert({{initialNames[0], firstDancer},
                  {initialNames[1], secondDancer},
                  {initialNames[2], thirdDancer}});
}

void Horo::justAdd(const string &newDancerName, const string &leftDancerName, const string &rightDancerName) {
  Dancer *newDancer = new Dancer(newDancerName);

  newDancer->setDancersInBothSides(dancers[leftDancerName],
                                   dancers[rightDancerName]);
  dancers[leftDancerName]->setDancerInRight(newDancer);
  dancers[rightDancerName]->setDancerInLeft(newDancer);

  dancers.insert({{newDancerName, newDancer}});
}

void Horo::justRemove(const string &dancerName) {
  dancers[dancerName]->getDancerInLeft()->setDancerInRight(
      dancers[dancerName]->getDancerInRight());
  dancers[dancerName]->getDancerInRight()->setDancerInLeft(
      dancers[dancerName]->getDancerInLeft());
  dancers.erase(dancerName);
}

void Horo::justSwap(const string &dancerNameOne, const string &dancerNameTwo) {

  Dancer *dancerOne = dancers[dancerNameOne];
  Dancer *dancerTwo = dancers[dancerNameTwo];

  bool aHoldB = dancerOne->isHoldDancerInRight();
  bool bHoldA = dancerTwo->isHoldDancerInLeft();

  Dancer *temp = dancerOne->getDancerInLeft();
  temp->setDancerInRight(dancerTwo, false);
  dancerTwo->setDancerInLeft(temp, false);
  dancerOne->setDancersInBothSides(dancerTwo, dancerTwo->getDancerInRight(),'l');
  dancerOne->getDancerInRight()->setDancerInLeft(dancerOne, false);
  dancerTwo->setDancerInRight(dancerOne, bHoldA);
}


Horo::Horo(const array<string, 3> &initialNames) { initialAdd(initialNames); }


void Horo::add(const string &newDancerName, const string &leftDancerName, const string &rightDancerName) {
  if (dancers.empty()) {
    initialAdd({newDancerName, leftDancerName, rightDancerName});
  }
  else if (isExistDancerWithName(newDancerName)) {
    throw runtime_error("The dancer with name " + newDancerName +
                        " already exists.");
  }
  else if (!isExistDancerWithName(leftDancerName)) {
    throw runtime_error("The dancer with name " + leftDancerName +
                        " does not exist.");
  }
  else if (!isExistDancerWithName(rightDancerName)) {
    throw runtime_error("The dancer with name " + rightDancerName +
                        " does not exist.");
  }
  else if (!areDancersAdjacent(leftDancerName, rightDancerName)) {
    throw runtime_error("The dancers with names " + leftDancerName +
                        " and " + rightDancerName + " are not adjacent.");
  }
  else {
    justAdd(newDancerName, leftDancerName, rightDancerName);
  }
}

void Horo::remove(const string &dancerName) {
  if (!isExistDancerWithName(dancerName)) {
    throw runtime_error("The dancer with name " + dancerName +
                        " does not exist.");
  }
  if (dancers[dancerName]->isHoldDancerInLeft() ||
      dancers[dancerName]->isHoldDancerInRight()) {
    throw runtime_error(dancerName + " hold another dancer.");
  }
  else if (dancers[dancerName]->getDancerInLeft()->isHoldDancerInRight() ||
           dancers[dancerName]->getDancerInRight()->isHoldDancerInLeft()) {
    throw runtime_error("Another dancer hold " + dancerName + ".");
  }
  else {
    justRemove(dancerName);
    if (dancers.size() == 2) {
      throw runtime_error("There are too few people left in the dance.");
    }
  }
}

void Horo::swap(const string &dancerNameOne, const string &dancerNameTwo) {
  if (!isExistDancerWithName(dancerNameOne)) {
    throw runtime_error("The dancer with name " + dancerNameOne + " does not exist.");
  }
  else if(!isExistDancerWithName(dancerNameTwo)) {
    throw runtime_error("The dancer with name " + dancerNameTwo + " does not exist.");
  }

  if (areDancersAdjacent(dancerNameOne, dancerNameTwo)) {
    if (dancers[dancerNameOne]->isHoldDancerInLeft() ||
        dancers[dancerNameTwo]->isHoldDancerInRight() ||
        dancers[dancerNameOne]->getDancerInLeft()->isHoldDancerInRight() ||
        dancers[dancerNameTwo]->getDancerInRight()->isHoldDancerInLeft()) {

      throw runtime_error("The dancers with names " + dancerNameOne + " and " + dancerNameTwo + " are linked to the dance");
    }
    else {
      justSwap(dancerNameOne, dancerNameTwo);
    }
  }
  else if (areDancersAdjacent(dancerNameTwo, dancerNameOne)) {
    swap(dancerNameTwo, dancerNameOne);
  }
  else {
    throw runtime_error("The dancers with names " + dancerNameOne + " and " + dancerNameTwo + " are not adjacent.");
  }
}