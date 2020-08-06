#include "CommandParser.h"

void ComandParser::loadCommands() {
  std::ifstream inputFile(pathToFile);

  if (inputFile.fail()) {
    std::cerr << "File " << pathToFile << " couldn't be opened!\n" << std::endl;
  }

  int numberOfParameters;
  string command;

  while (!inputFile.eof()) {
    inputFile >> command >> numberOfParameters;
    commands.insert({command, numberOfParameters});
  }

  inputFile.close();

  /*for (auto it = commands.begin(); it != commands.end(); it++) {
   cout << it->second << endl;
 }*/
}

vector<string> ComandParser::split(string s, string delimiter) {
  s += delimiter;
  size_t pos_start = 0, pos_end, delim_len = delimiter.length();
  string token;
  vector<string> res;

  while ((pos_end = s.find(delimiter, pos_start)) != string::npos) {
    token = s.substr(pos_start, pos_end - pos_start);
    pos_start = pos_end + delim_len;
   if (token != "") res.push_back(token);
  }

  //res.push_back(s.substr(pos_start));
  return res;
}

ComandParser::ComandParser() { this->loadCommands(); }

ComandParser::ComandParser(string pathToFile) : pathToFile(pathToFile) {
  this->loadCommands();
}

vector<string> ComandParser::verifyComand(string commandLine) {
  vector<string> command = split(commandLine, " ");
  int numberOfParameters = commands[command[0]];
  if (numberOfParameters == 0) {
    throw runtime_error("Command " + command[0] +
                        " does not exist\nType help for more information\n");
  }
  if (numberOfParameters != command.size()) {
    // TODO write compatible exeption
    throw invalid_argument(
        "Command " + command[0] +
        " have wrong number of parameters\nType help for more information\n");
  }
  return command;
}
