#include "FileManager.h"

#include <fstream>
#include <iostream>
#include <vector>


using namespace std;

FileManager::FileManager(string file) : fileName(file) {}

FileManager::FileManager() : fileName(nullptr) {}

FileManager::~FileManager() {}

string FileManager::getFileName() const { return fileName; }

void FileManager::setFileName(string file) { fileName = file; }

vector<string> FileManager::loadDataFromFile() {
  ifstream inFile;
  inFile.open(fileName);
  if (inFile.fail()) {
    cerr << "fail open a file" << endl;
  }
  size_t size;
  inFile >> size;
  vector<string> names;
  names.resize(size);

  for (string &name : names) {
    inFile >> name;
  }
  inFile.close();
  return names;
}

void FileManager::saveDataInFile(vector<string> text) {
  ofstream out;
  out.open(fileName);
  out << text.size() << endl;
  for (size_t i = 0; i < text.size(); i++) {
    out << text[i] << endl;
  }
  out.close();
}
