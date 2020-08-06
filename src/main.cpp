#include "ModelManager.h"
#include "Presenter.h"
#include <string>

int main() {
  Presenter present("dancers.txt","commands.txt");
  present.buildDance();
  present.play();

}
