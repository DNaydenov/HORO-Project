#include "Presenter.h"

Presenter::Presenter(string pathNames, string pathCommands)
    : model(pathNames), parser(pathCommands) {}

Presenter::Presenter(string pathNames) : model(pathNames) {}

void Presenter::play() {
  string input;
  string welcome = "Input a command:\n";
  while (input != "exit") {
    cout << welcome;
    getline(cin, input);
    if (input == "exit") break;
    if (input[0] == ' ') {
      cout << "wrong input - the can not start with a white space" << endl;
    } else {
      vector<string> command;
      bool failed = false;
      try {
        command = parser.verifyComand(input);
      } catch (const char* e) {
        failed = true;
        cout << e << endl;
      }
      if (!failed) {
        try {
          executeCommand(command);
        } catch (const std::exception& e) {
          cout << e.what() << endl;
        }
      }
    }
  }
  cout << "do you want to save the changes? y/n" << endl;
  char answer;
  cin >> answer;
  if (answer == 'y') save();
}

void Presenter::buildDance() { model.buildDance(); }

void Presenter::executeCommand(vector<string> commandAndParameters) {
  string command = commandAndParameters[0];
  commandAndParameters.erase(commandAndParameters.begin());
  model.executeCommand(command, commandAndParameters);
}

void Presenter::save() { model.saveDataInFile(); }

void Presenter::exit(bool flag) {
  if (flag) save();
}
