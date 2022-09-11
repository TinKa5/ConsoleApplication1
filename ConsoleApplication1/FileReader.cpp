#include "Reader.h"

using namespace std;

 vector<string> read(string path) {
     
    vector<string> res;
    string line;
    ifstream myfile(path);
    
    if (myfile.is_open()){
        
        while (getline(myfile, line))
        {
            res.push_back(line);
        }
        myfile.close();
    }

    else cout << "Unable to open file";

	return res;
}

 bool write(string filename, map<string, map<string, int>> data) {

     ofstream fout(filename);
     if (!fout.is_open())
         return false;

     fout << "NAME;DATE\n";

     for (auto const& pair1 : data) {
         auto key = pair1.first;
         map<string, int> values = pair1.second;
         
         for (auto const& pair2 : values) {
             fout << key + ';' + pair2.first + ';' + to_string(pair2.second) + '\n';
         }
     }
     
     fout.close();
     return true;
 }
