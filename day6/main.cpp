#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;


int level1(ifstream &file) {
    string line;
    int sum = 0;
    while(!file.eof()){
        getline(file,line);
        map<char,bool> l;
        while(!line.empty()){
            for(int i = 0; i < line.size(); i++){
                l[line[i]] = true;
            }
            getline(file,line);
        }
        sum += l.size();
    }
    return sum;
}

int print_bool(bool a[26]){
    int t = 0;
    for(int i = 0; i < 26; i++){
        if(a[i]){
            t++;
            cout << (char)(i+97) << ":" << a[i] << " ";
        }
    }
    cout << endl;
    return t;
}

long int level2(ifstream &file) {
    string line;
    int sum = 0;
    while(!file.eof()){
        getline(file,line);
        bool g[26];
        for( int i = 0; i < 26; i++){
            g[i] = true;
        }
        print_bool(g);
        while(!line.empty()){
            bool p[26] = {false};
            for(int i = 0; i < line.size(); i++){
                int t = ((int) line[i]) - 97;
                p[t] = true;
            }
            for( int i = 0; i < 26; i++){
                if(!p[i]){
                    g[i]=false;
                }
            }
            getline(file,line);
        }
        sum += print_bool(g);
    }
    return sum;
}

int main() {
  ifstream file;
  file.open("input");
  long int out = level2(file);
  cout << endl << "Result: " << out << endl;
}
