#include <iostream>
#include <sstream>
#include <string>
#include "ReaderWriter.h"
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
    ostringstream oss;
    oss << put_time(&tm, "%B %Y");
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
    cout << "Job is starting...\n";

    vector<string> res1= READER_WRITER::read("test1.txt");

    map<string, map<string, int>> hours;

    for (auto const& element : res1) {

        vector<string> lines = split(element, ';');        
        
        addToMap(lines[0], modifyDate(lines[6]), stoi(lines[7]), hours);        
    }
    
    if (READER_WRITER::write("test2.csv", hours)) cout << "Sucsessfully complited.";
    return 0;    
}