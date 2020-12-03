#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int level1(ifstream &file) {
  int i = 0, j = 0;
  vector<int> list;
  while (true) {
    int in;
    file >> in;
    i = list.size();
    for (j = 0; j < i; j++) {
      if (in + list[j] == 2020) {
        return in * list[j];
      }
    }
    list.push_back(in);
  }
}

int level2(ifstream &file) {
  int i = 0, j = 0;
  bool ind[2020];
  vector<int> list;
  int nums[2020][2];
  while (true) {
    int in;
    file >> in;
    if (ind[2020 - in]) {
      cout << in << " " << nums[2020 - in][0] << " " << nums[2020 - in][1]
           << endl;
      return in * nums[2020 - in][0] * nums[2020 - in][1];
    }
    i = list.size();
    for (j = 0; j < i; j++) {
      int sum = in + list[j];
      if (sum < 2020 && !ind[sum]) {
        ind[sum] = true;
        nums[sum][0] = in;
        nums[sum][1] = list[j];
      }
    }
    list.push_back(in);
  }
}

int main() {
  ifstream file;
  file.open("input");
  int out = level2(file);
  cout << endl << "Result: " << out << endl;
}
