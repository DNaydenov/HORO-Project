#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include "Dancer.h"

using namespace std;

class Dance {
 protected:
  std::unordered_map<std::string, Dancer *> dancers;

 public:

  bool isExistDancerWithName(const string &name);
  bool isExistDancerWithName(const vector<string> &names);

  bool areDancersAdjacent(const std::string &left, const std::string &right);
  bool areDancersAdjacent(const std::vector<std::string> &names);

  size_t getNumberOfDancers() const;
  std::vector<std::string> getNames();

  //Application Programming Interface

  void release(const std::string &name, char side);
  void grab(const std::string &name, char side);

  virtual void add(const std::string &dancer, const std::string &leftDancer, const std::string &rightDancer) = 0;
  virtual void remove(const std::string &name) = 0;
  virtual void swap(const std::string &first, const std::string &second) = 0;

  void info(const std::string &name);
  void print() const;


  //Application Programming Interface - vector edition
  void release(const std::vector<std::string> &arguments);
  void grab(const std::vector<std::string> &arguments);

  void add(const std::vector<std::string> &arguments);
  void remove(const std::vector<std::string> &arguments);
  void swap(const std::vector<std::string> &arguments);

  void info(const std::vector<std::string> &arguments);
  void print(const std::vector<std::string> &arguments);
};
