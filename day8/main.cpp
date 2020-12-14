#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

struct op {
  string op;
  int num;
  char sign;
};

int level1(ifstream &file) {
  vector<stringstream> inst;
  string line;
  while (getline(file, line)) {
    inst.push_back(stringstream(line));
  }
  bool run[inst.size()] = {false};
  int i = 0, acc = 0;
  while (!run[i]) {
    run[i] = true;
    string op;
    char sign;
    int num;
    inst[i] >> op;
    inst[i] >> sign;
    inst[i] >> num;
    cout << op << " " << sign << " " << num << endl;
    if (op == "nop") {
      i++;
    } else if (op == "acc") {
      i++;
      if (sign == '-') {
        acc -= num;
      } else {
        acc += num;
      }
    } else if (op == "jmp") {
      if (sign == '-') {
        i -= num;
      } else {
        i += num;
      }
    }
  }
  return acc;
}

long int level2(ifstream &file) {
  vector<struct op> inst;
  string line;
  while (getline(file, line)) {
    struct op a;
    stringstream sline(line);
    sline >> a.op;
    sline >> a.sign;
    sline >> a.num;
    inst.push_back(a);
  }
  bool run[inst.size()] = {false};
  int i = 0, acc = 0;
  vector<int> loop;
  while (!run[i]) {
    run[i] = true;
    if (inst[i].op == "nop") {
      loop.push_back(i);
      i++;
    } else if (inst[i].op == "acc") {
      if (inst[i].sign == '-') {
        acc -= inst[i].num;
      } else {
        acc += inst[i].num;
      }
      i++;
    } else if (inst[i].op == "jmp") {
      loop.push_back(i);
      if (inst[i].sign == '-') {
        i -= inst[i].num;
      } else {
        i += inst[i].num;
      }
    }
  }
  cout << loop.size() << endl;
  for (int j = 0; j < loop.size(); j++) {
    int k = loop[j];
    cout << "Try instruction: " << k << endl;
    cout << inst[k].op << " " << inst[k].sign << " " << inst[k].num << endl;
    if (inst[k].op == "nop") {
      inst[k].op = "jmp";
    } else {
      inst[k].op = "nop";
    }
    cout << inst[k].op << " " << inst[k].sign << " " << inst[k].num << endl;
    bool runt[inst.size()] = {false};
    i = 0, acc = 0;
    while (!runt[i] && i < inst.size() && i >= 0) {
      runt[i] = true;
      if (inst[i].op == "nop") {
        i++;
      } else if (inst[i].op == "acc") {
        if (inst[i].sign == '-') {
          acc -= inst[i].num;
        } else {
          acc += inst[i].num;
        }
        i++;
      } else if (inst[i].op == "jmp") {
        if (inst[i].sign == '-') {
          i -= inst[i].num;
        } else {
          i += inst[i].num;
        }
      }
    }
    cout << "Did run to " << i << endl;
    if(i == inst.size()){
        cout << "Changed instruction: " << k << endl;
        break;
    }
    if (inst[k].op == "nop") {
      inst[k].op = "jmp";
    } else {
      inst[k].op = "nop";
    }
    cout << inst[k].op << " " << inst[k].sign << " " << inst[k].num << endl;
  }
  return acc;
}

int main() {
  ifstream file;
  file.open("input");
  long int out = level2(file);
  cout << endl << "Result: " << out << endl;
}
