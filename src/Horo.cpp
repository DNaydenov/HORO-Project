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

Horo::Horo(const array<string, 3> &initialNames) { initialAdd(initialNames); }

void Horo::add(const string &newDancerName, const string &leftDancerName, const string &rightDancerName) {
  if (dancers.empty()) {
    initialAdd({newDancerName, leftDancerName, rightDancerName});
  } else if (isExistDancerWithName(newDancerName)) {
    throw runtime_error("The dancer with name " + newDancerName +
                        " already exists.");
  } else if (!isExistDancerWithName(leftDancerName)) {
    throw runtime_error("The dancer with name " + leftDancerName +
                        " does not exist.");
  } else if (!isExistDancerWithName(rightDancerName)) {
    throw runtime_error("The dancer with name " + rightDancerName +
                        " does not exist.");
  } else if (!areDancersAdjacent(leftDancerName, rightDancerName)) {
    throw runtime_error("The dancers with names " + leftDancerName + " and " +
                        rightDancerName + " are not adjacent.");
  } else {
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
  } else if (dancers[dancerName]->getDancerInLeft()->isHoldDancerInRight() ||
             dancers[dancerName]->getDancerInRight()->isHoldDancerInLeft()) {
    throw runtime_error("Another dancer hold " + dancerName + ".");
  } else {
    justRemove(dancerName);
    if (dancers.size() == 2) {
      // exit();
    }
  }
}

void Horo::swap(const string &A, const string &B) {
  if (!isExistDancerWithName(A) || !isExistDancerWithName(B)) {
    throw runtime_error("The dancer with name " + A + " or " + B + " does not exist.");
  }
  Dancer *dancerA = dancers[A];
  Dancer *dancerB = dancers[B];

  if (areDancersAdjacent(A, B)) {
    if (!dancers[A]->isHoldDancerInLeft() &&
        !dancers[B]->isHoldDancerInRight() &&
        !dancers[A]->getDancerInLeft()->isHoldDancerInRight() &&
        !dancers[B]->getDancerInRight()->isHoldDancerInLeft()) {

      bool aHoldB = dancerA->isHoldDancerInRight();
      bool bHoldA = dancerB->isHoldDancerInLeft();

      Dancer *temp = dancerA->getDancerInLeft();
      temp->setDancerInRight(dancerB, false);
      dancerB->setDancerInLeft(temp, false);
      dancerA->setDancersInBothSides(dancerB, dancerB->getDancerInRight(),
                                     aHoldB, false);
      dancerA->getDancerInRight()->setDancerInLeft(dancerA, false);
      dancerB->setDancerInRight(dancerA, bHoldA);
    } else {
      throw runtime_error("The dancers with names " + A + " and " + B + " are linked to the dance");
    }
  } else if (areDancersAdjacent(B, A)) {
    swap(B, A);
  } else {
    throw runtime_error("The dancers with names " + A + " and " + B + " are not adjacent.");
  }
}