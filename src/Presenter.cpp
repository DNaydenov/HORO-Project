#include "Presenter.h"

Presenter::Presenter(string pathNames, string pathCommands)
    : model(pathNames), parser(pathCommands) {}

Presenter::Presenter(string pathNames) : model(pathNames) {}

void Presenter::play() {
  string input;
  string welcome = "Input a command:/n";
  while (input != "exit") {
    cout << welcome;
    cin >> input;

    /*try {
      executeCommand(parser.verifyComand(input));
    } catch (const std::exception& e) {
      cout << e.what() << endl;
    }*/
    // TODO catch exeptions
  }
}

void Presenter::buildDance() { model.buildDance(); }

void Presenter::updateView() {}

void Presenter::save() { model.saveDataInFile(); }

void Presenter::exit(bool flag) {
  if (flag) save();
}
