#pragma once
#include <iostream>
#include <unordered_map>
#include <vector>

#include "FileManager.h"

using namespace std;

class ComandParser {
  string pathToFile = "commands.txt";
  unordered_map<std::string, int> commands;

 public:
  ComandParser();
  ComandParser(string pathToFile);
  ~ComandParser() = default;

  vector<string> verifyComand(string commandLine);

 private:
  vector<string> split(string s, string delimiter);
  void loadCommands();
};
