#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Dancer.h"

class Dance {
 protected:
  std::unordered_map<std::string, Dancer*> dancers;

 public:

  bool isExistDancerWithName(const std::string &name);
  bool isExistDancerWithName(const std::vector<std::string> &names);

  bool areDancersAdjacent(const std::string &left, const std::string &right);
  bool areDancersAdjacent(const std::vector<std::string> &names);

  size_t getNumberOfDancers() const;
  std::vector<std::string> getNames();

  void release(const std::string &name, char side);
  void grab(const std::string &name, char side);
  void info(const std::string &name);
  void print() const;

  virtual void add(const std::string &dancer, const std::string &leftDancer, const std::string &rightDancer) = 0;
  virtual void remove(const std::string &name) = 0;
  virtual void swap(const std::string& first, const std::string& second) = 0;
};
