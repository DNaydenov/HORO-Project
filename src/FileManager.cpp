#include <fstream>
#include <iostream>
#include "FileManager.h"

using namespace std;

FileManager::FileManager(string file) : fileName(file)
{
}

FileManager::FileManager() : fileName(nullptr)
{}

FileManager::~FileManager() {}

void FileManager::setFileName(string file)
{
  fileName = file;
}

void FileManager::loadDataFromFile()
{
  ifstream inFile;
  inFile.open(fileName);
  if (inFile.fail())
  {
    cerr << "fail open a file" << endl;
  }
  inFile.close();
}

void FileManager::saveDataInFile(string text)
{
  ofstream out;
  out.open(fileName);
  out << text << endl;
  out.close();
}
