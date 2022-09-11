#ifndef READER
#define READER

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>


std::vector<std::string> read(std::string path);
bool write(std::string filename, std::map < std::string, std::map<std::string, int >> data);

#endif // !READER

