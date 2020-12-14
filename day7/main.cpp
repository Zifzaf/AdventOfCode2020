#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string.h>
#include <vector>
#include <set>
using namespace std;

void add_array(int a[],int b[], int c){
    for (int i = 0; i < c; ++i)
        {
            a[i] = a[i] + b[i];
        }
}

int level1(ifstream &file) {
    map<string,set<string>> m;
    string line;
    while(getline(file,line)){
        stringstream sline(line);
        string outbag,bagc1, bagc2, next;
        sline >> bagc1;
        sline >> bagc2;
        outbag = bagc1 + bagc2;
        sline >> next;
        sline >> next;
        int inbagc;
        while(sline.tellg() != -1){
            sline >> inbagc;
            sline >> bagc1;
            sline >> bagc2;
            bagc1 = bagc1 + bagc2;
            if(m.count(bagc1) == 0){
                m[bagc1] = set<string>();
            }
            m[bagc1].insert(outbag);
            sline >> next;
        }
    }
    set<string> out;
    for (auto elem : m["shinygold"]){
        out.insert(elem);
    }
    int prev = 0;
    while(prev < out.size()){
        prev = out.size();
        for (auto j : out){
            for (auto i : m[j]){
                out.insert(i);
            }
        }
    }

    return out.size();
}

long int level2(ifstream &file) {
}

int main() {
  ifstream file;
  file.open("input");
  long int out = level1(file);
  cout << endl << "Result: " << out << endl;
}
