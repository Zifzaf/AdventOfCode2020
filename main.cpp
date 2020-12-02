#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int day1level1(ifstream &file) {
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

int day1level2(ifstream &file) {
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

int day2level1(ifstream &file) {
  int min, max, count, out = 0;
  char letter, next, s;
  while (file.peek() != EOF) {
    count = 0;
    file >> min;
    file >> next;
    file >> max;
    file >> letter;
    file >> next;
    file >> next;
    cout << min << " " << max << " " << letter << endl;
    while (next != '\n' ) {
      if (next == letter) {
        count++;
      }
      file.get(next);
      cout << next;
    }
    if (count <= max && count >= min) {
      out++;
    }
  }
  return out;
}

int day2level2(ifstream &file) {
  bool check;
  int one, two, out = 0, t;
  char letter, next, s;
  while (file.peek() != EOF) {
    file >> one;
    file >> next;
    file >> two;
    file >> letter;
    file >> next;
    file >> next;
    cout << one << " " << two << " " << letter << endl;
    t = 1;
    check = false;
    while (next != '\n' && t < 100) {
      if ((t == one || t == two) && next == letter) {
        check = !check;
      }
      file.get(next);
      cout << next;
      t++;
    }
    if (check) {
      out++;
    }
  }
  return out;
}

int main() {
  ifstream file;
  file.open("input");
  int out = day2level2(file);
  cout << endl << "Result: " << out << endl;
}
