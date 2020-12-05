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
    int max = 0;
    while(getline(file,line)){
        string srow,scol;
        for(int i = 0; i < 7; i++){
            if( line[i] == 'F'){
                srow.append("0");
            } else {
                srow.append("1");
            }
        }
        for(int i = 7; i < 10; i++){
            if( line[i] == 'L'){
                scol.append("0");
            } else {
                scol.append("1");
            }
        }
        int row = stoi(srow,0,2);
        int col = stoi(scol,0,2);
        int id = 8 * row + col;
        if( id > max){
            max = id;
        }
    }
    return max;
}

long int level2(ifstream &file) {
    string line;
    int max = 0;
    int min = 1023;
    bool seats[1023] = {false};
    while(getline(file,line)){
        string srow,scol;
        for(int i = 0; i < 7; i++){
            if( line[i] == 'F'){
                srow.append("0");
            } else {
                srow.append("1");
            }
        }
        for(int i = 7; i < 10; i++){
            if( line[i] == 'L'){
                scol.append("0");
            } else {
                scol.append("1");
            }
        }
        int row = stoi(srow,0,2);
        int col = stoi(scol,0,2);
        int id = 8 * row + col;
        seats[id] = true;
        if(id > max){
            max = id;
        }
        if(id < min){
            min = id;
        }
    }
    for (int i = min + 1; i < max; i++){
        if(!seats[i]){
            return i;
        }
    }
    return -1;
}

int main() {
  ifstream file;
  file.open("input");
  long int out = level2(file);
  cout << endl << "Result: " << out << endl;
}
