#include "FileManager.h"

FileManager::FileManager(std::string filename) : pathToFile(std::move(filename)) {}

const std::string & FileManager::getFilename() const { return pathToFile; }

void FileManager::setFilename(const std::string &filename) { pathToFile = filename; }

void FileManager::loadDataFromFile(std::vector<std::string> &names) {
  std::ifstream inputFile(pathToFile);

  if(inputFile.fail()) {
    std::cerr << "File " << pathToFile << " couldn't be opened!\n" << std::endl;
  }

  size_t numberOfDancers;
  inputFile >> numberOfDancers;
  names.resize(numberOfDancers);

  for (std::string &name : names) {
    inputFile >> name;
  }

  inputFile.close();
}

void FileManager::saveDataInFile(const std::vector<std::string> &names) {
  std::ofstream outputFile(pathToFile);

  outputFile << names.size() << std::endl;

  for (const std::string & name : names) {
    outputFile << name << std::endl;
  }

  outputFile.close();
}
