#include <iostream>
#include <sstream>
#include <string>
#include "Reader.h"
#include <vector>
#include <iomanip>
#include <map>

using namespace std;

vector<string> split(string s, char del) {
    
    stringstream ss(s);
    string word;
    vector<string> result;

    while (!ss.eof()) {
        getline(ss, word, del);
        result.push_back(word);
    }

    return result;
}

//convert "2022-01-19" -> "January 2022"
string modifyDate(string date) {
    
    tm tm = {};
    stringstream ss(date);
    ss >> get_time(&tm, "%Y-%m-%d");
    std::ostringstream oss;
    oss << std::put_time(&tm, "%B %Y");
    return oss.str();
}


void addToMap(string name, string date, int amount, map<string, map<string, int>> &hours) {
    if (hours.find(name) != hours.end()) {
        map<string, int> &byName = hours[name];
        byName[date] = byName[date] +amount;
    }else {
        hours[name].insert({ date, amount });
    }

    return;
}


int main()
{
    std::cout << "Job is starting...\n";

    std::vector<std::string> res1= READER::read("test1.txt");

    map<string, map<string, int>> hours;

    for (auto const& element : res1) {

        std::vector<std::string> lines = split(element, ';');        
        
        addToMap(lines[0], modifyDate(lines[6]), stoi(lines[7]), hours);        
    }
    
    if (READER::write("test2.csv", hours)) std::cout << "Sucsessfully complited.";
    return 0;    
}