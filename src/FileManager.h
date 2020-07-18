#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class FileManager {

  std::string pathToFile;

 public:
  explicit FileManager(std::string filename);

  const std::string & getFilename() const;
  void setFilename(const std::string &filename);

  void loadDataFromFile(std::vector<std::string> &names);
  void saveDataInFile(const std::vector<std::string> &names);
};