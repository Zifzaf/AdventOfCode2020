#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;


int level1(ifstream &file) {
    char line[256];
    file.getline(line,256);
    int lineLength = 0;
    while(line[lineLength] != '\0'){
        lineLength++;
    }
    int index = 3, out = 0;
    while( file.peek() != EOF){
        file.getline(line,256);
        if (line[index] == '#'){
            out++;
        }
        index = (index + 3) %  lineLength;
    }
    return out;
}

long int level2(ifstream &file) {
    char line[256];
    file.getline(line,256);
    int lineLength = 0;
    while(line[lineLength] != '\0'){
        lineLength++;
    }
    int numSlopes = 5,lineNum = 1,i;
    int slopes[][4] ={
    { 1, 1, 1, 0},
    { 3, 1, 3, 0},
    { 5, 1, 5, 0},
    { 7, 1, 7, 0},
    { 1, 2, 1, 0}};
    while( file.peek() != EOF){
        file.getline(line,256);
        for( i = 0; i < numSlopes; i++){
            if(lineNum % slopes[i][1] == 0){
                if ( line[slopes[i][2]] == '#'){
                    slopes[i][3] += 1;
                }
                slopes[i][2] = (slopes[i][2] + slopes[i][0]) % lineLength;
            }
        }
        lineNum++;
    }
    long int out = 1;
    for( i = 0; i < numSlopes; i++){
        cout << slopes[i][3] << endl;
        out = out * slopes[i][3];
    }
    return out;
}

int main() {
  ifstream file;
  file.open("input");
  long int out = level2(file);
  cout << endl << "Result: " << out << endl;
}
