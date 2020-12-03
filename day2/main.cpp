#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int level1(ifstream &file) {
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

int level2(ifstream &file) {
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
  int out = level2(file);
  cout << endl << "Result: " << out << endl;
}
