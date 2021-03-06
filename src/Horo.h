#pragma once
#include <array>
#include <exception>
#include "Dance.h"
using namespace std;

class Horo : public Dance {

    void initialAdd(const array<string,3> &initialNames);
    void justAdd(const string &newDancerName, const string &leftDancerName, const string &rightDancerName);
    void justRemove(const string &dancerName);
    void justSwap(const string &dancerNameOne, const string &dancerNameTwo);

 public:

     explicit Horo(const array<string,3> &initialNames);

     void add(const string &newDancerName, const string &leftDancerName, const string &rightDancerName) override;
     void remove(const string &dancerName) override;
     void swap(const string &dancerNameOne, const string &dancerNameTwo) override;
};

