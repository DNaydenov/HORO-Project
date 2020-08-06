#include "Presenter.h"

Presenter::Presenter(string pathNames, string pathCommands)
    : model(pathNames), parser(pathCommands) {}

Presenter::Presenter(string pathNames) : model(pathNames) {}

void Presenter::play() {
  string input;
  help();
  string welcome = "Input a command:\n>";
  while (input != "exit") {
    cout << welcome;
    getline(cin, input);
    vector<string> command;
    bool failed = false;
    try {
      command = parser.verifyComand(input);
    } catch (const std::exception& e) {
      failed = true;
      cout << e.what() << endl;
    }
    if (!failed) {
      if (command[0] == "help")
        help();
      else if (command[0] == "exit")
        break;
      else {
        try {
          executeCommand(command);
        } catch (const std::exception& e) {
          if (e.what() == "...and the music stops!") exit();
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

void Presenter::help() const {
  std::cout << "The available commands are:\n";
  std::cout << "\tprint -> prints all participants in the dance\n";
  std::cout << "\tinfo <who|all>\n";
  std::cout << "\tadd <who> <left dancer label> <right dancer label>\n";
  std::cout << "\tremove <who>\n";
  std::cout << "\tswap <who1> <who2>\n";
  std::cout << "\tgrab <who> <left|right|both>\n";
  std::cout << "\trelease <who> <left|right|both>\n";
  std::cout << "\texit\n";
}
