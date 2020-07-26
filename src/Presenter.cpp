#include "Presenter.h"

Presenter::Presenter(string pathNames, string pathCommands)
    : model(pathNames), parser(pathCommands) {}

Presenter::Presenter(string pathNames) : model(pathNames) {}

void Presenter::play() {
  string input; 
  string welcome = "Input a command:/n";
  while (true) {
  cout << welcome;
  cin >> input;
  executeCommand(parser.verifyComand(input));
  //TODO catch exeptions
  }

}
