#pragma once
#include <exception>
#include "Dance.h"

class Horo : public Dance {

    void initialAdd(const string &firstDancerName, const string &secondDancerName, const string &thirdDancerName);
    void justAdd(const string &newDancerName, const string &leftDancerName, const string &rightDancerName);
    void justRemove(const string &dancerName);

 public:
    explicit Horo(const string &firstDancerName, const string &secondDancerName, const string &thirdDancerName);

    void add(const string &newDancerName, const string &leftDancerName, const string &rightDancerName) override;
    void remove(const string &dancerName) override;
    void swap(const string &firstDancerName, const string &secondDancerName) override;
};

