#include "ModelManager.h"

#include <utility>

#define ADD_COMMAND(command_name) commandsMap[#command_name] = &Dance::command_name
#define EXECUTE_COMMAND(command_name, arguments) (dance->*commandsMap[command_name])(arguments)


void ModelManager::initialMapping() {
  ADD_COMMAND(grab);
  ADD_COMMAND(release);
  ADD_COMMAND(info);
  ADD_COMMAND(print);
  ADD_COMMAND(add);
  ADD_COMMAND(remove);
  ADD_COMMAND(swap);
}

ModelManager::ModelManager(string file) : filename(std::move(file)){
  initialMapping();
}

void ModelManager::setFilename(const string &file) {
  filename = file;
}

void ModelManager::buildDance() {
  BuildManager manager(filename);
  manager.constructDanceFormation();
  dance = manager.getConstruction();
}

void ModelManager::saveDataInFile() const {
  FileManager fileManager(filename);
  fileManager.saveDataInFile(dance->getNames());
}

void ModelManager::executeCommand(const string &command, const vector<string> &arguments) {
  EXECUTE_COMMAND(command, arguments);
}