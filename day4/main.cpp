#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

template<typename K, typename V>
void print_map(map<K,V> const &m)
{
    cout << "{ ";
    for (auto const& pair: m) {
        cout << pair.first << ":" << pair.second << "  ";
    }
    cout << "}" << endl;

}

template<typename K, typename V>
void check_passport(map<K,V> const &p)
{
    int byr = stoi(p["byr"]);
    if (byr<1920 || byr>2002){
        return 0;
    }
    int iyr = stoi(p["iyr"]);
    if (iyr<2010 || iyr>2020){
        return 0;
    }
    int eyr = stoi(p["eyr"]);
    if (eyr<2020 || eyr>2030){
        return 0;
    }



}

int level1(ifstream &file) {
    string line;
    int out = 0;
    while(getline(file, line)){
        map<string,string> passport;
        int count = 0;
        do {
            stringstream linestream(line);
            string element;
            string prev;
            linestream >> element;
            do {
                size_t dd = element.find(':');
                string key = element.substr(0, dd);
                string value = element.substr(dd+1);
                if(key != "cid"){
                    count++;
                }
                passport[key] = value;
                prev = element;
                linestream >> element;
            } while(prev != element);
            getline(file,line);
        } while (!line.empty());
        if( count == 7){
            out++;
        }
    }
    return out;
}

long int level2(ifstream &file) {
    string line;
    int out = 0;
    while(getline(file, line)){
        map<string,string> passport;
        int count = 0;
        do {
            stringstream linestream(line);
            string element;
            string prev;
            linestream >> element;
            do {
                size_t dd = element.find(':');
                string key = element.substr(0, dd);
                string value = element.substr(dd+1);
                if(key != "cid"){
                    count++;
                }
                passport[key] = value;
                prev = element;
                linestream >> element;
            } while(prev != element);
            getline(file,line);
        } while (!line.empty());
        if( count == 7){
            out += check_passport(passport);
        }

    }
    return out;
}

int main() {
  ifstream file;
  file.open("input");
  long int out = level2(file);
  cout << endl << "Result: " << out << endl;
}
