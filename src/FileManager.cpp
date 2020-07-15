#include "FileManager.h"

#include <fstream>
#include <iostream>
#include <utility>
#include <vector>


using namespace std;

FileManager::FileManager(string file) : filename(std::move(file)) {}

const string & FileManager::getFilename() const { return filename; }

void FileManager::setFilename(const string &file) { filename = file; }

void FileManager::loadDataFromFile(vector<string> &names) {
  ifstream inputFile(filename);
  if (inputFile.fail()) {
    cerr << "fail open a file" << endl;
  }

  size_t size;
  inputFile >> size;
  names.resize(size);

  for (string &name : names) {
    inputFile >> name;
  }

  inputFile.close();
}

void FileManager::saveDataInFile(const vector<string> &names) {
  ofstream outputFile(filename);

  outputFile << names.size() << endl;

  for (const string & name : names) {
    outputFile << name << endl;
  }

  outputFile.close();
}
