#include "ModelManager.h"
#include "Presenter.h"
#include <string>


int main() {
  Presenter present("dancers.txt","commands.txt");
  present.buildDance();
  present.play();

  ModelManager M("dancers.txt");
  M.buildDance();

  M.executeCommand("release", {"Ivan","b"});
  M.executeCommand("release", {"aldi","r"});
  M.executeCommand("release", {"Pesho","l"});

  M.executeCommand("remove",{"Ivan"});

  for (const auto& name : M.dance->getNames()) {
    M.executeCommand("info",{name});
  }

}
