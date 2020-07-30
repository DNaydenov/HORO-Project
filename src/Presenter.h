#pragma once
#include "CommandParser.h"
#include "ModelManager.h"

class Presenter {
 private:
  ModelManager model;
  ComandParser parser;

 public:
  Presenter(string pathNames, string pathCommands);
  Presenter(string pathNames);

  ~Presenter() = default;
  void play();
  void waitForEvent();
  void buildDance();
  void executeCommand(vector<string>);
  void updateView(); // print info 
  void save();

 private:
  void exit(bool flag = false);
};
