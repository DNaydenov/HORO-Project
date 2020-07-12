#pragma once
#include <exception>
#include "Dance.h"

class Horo : public Dance {

 public:

    explicit Horo(const vector<string> &names);

    void add(const string &B, const string &A, const string &C) override;

    void add(const vector<string> &names);

    void remove(const string &D) override;

    void swap(const string &A, const string &B) override;
};

