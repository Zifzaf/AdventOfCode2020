#include <algorithm>
#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string.h>
#include <vector>
using namespace std;

int count_occ(vector<string> &m, int i, int j) {
  int oc = 0;
  if (i + 1 < m.size() && j + 1 < m[i].size() && m[i + 1][j + 1] == '#') {
    oc++;
  }
  if (i + 1 < m.size() && m[i + 1][j] == '#') {
    oc++;
  }
  if (i + 1 < m.size() && 0 <= j - 1 && m[i + 1][j - 1] == '#') {
    oc++;
  }
  if (0 <= i - 1 && j + 1 < m[i].size() && m[i - 1][j + 1] == '#') {
    oc++;
  }
  if (0 <= i - 1 && m[i - 1][j] == '#') {
    oc++;
  }
  if (0 <= i - 1 && 0 <= j - 1 && m[i - 1][j - 1] == '#') {
    oc++;
  }
  if (j + 1 < m[i].size() && m[i][j + 1] == '#') {
    oc++;
  }
  if (0 <= j - 1 && m[i][j - 1] == '#') {
    oc++;
  }
  return oc;
}

void print_m(const vector<string> &m) {
  for (int i = 0; i < m.size(); i++) {
    cout << m[i] << endl;
  }
}

long int level1(ifstream &file) {
  vector<string> m;
  string line;
  while (getline(file, line)) {
    m.push_back(line);
  }
  int ch = 1;
  while (ch) {
    ch = 0;
    vector<int> ci, cj;
    for (int i = 0; i < m.size(); i++) {
      for (int j = 0; j < m[i].size(); j++) {
        if (m[i][j] == '.') {
          continue;
        }
        if (m[i][j] == '#') {
          int occ = count_occ(m, i, j);
          if (occ > 3) {
            cj.push_back(j);
            ci.push_back(i);
          }
        }
        if (m[i][j] == 'L') {
          int occ = count_occ(m, i, j);
          if (occ == 0) {
            cj.push_back(j);
            ci.push_back(i);
          }
        }
      }
    }
    ch = cj.size();
    for (int t = 0; t < ch; t++) {
      if (m[ci[t]][cj[t]] == '#') {
        m[ci[t]][cj[t]] = 'L';
      } else if (m[ci[t]][cj[t]] == 'L') {
        m[ci[t]][cj[t]] = '#';
      } else {
        cout << "Ups!" << endl;
      }
    }
  }
  int out = 0;
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[i].size(); j++) {
      if (m[i][j] == '#') {
        out++;
      }
    }
  }
  return out;
}

int count_occ2(vector<string> &m, int i, int j) {
  int oc = 0;
  int k = 1;
  while (i + k < m.size() && j + k < m[i].size()) {
    if (m[i + k][j + k] == '#') {
      oc++;
      break;
    }
    if (m[i + k][j + k] == 'L') {
      break;
    }
    k++;
  }
  k = 1;
  while (i + k < m.size()) {
    if (m[i + k][j] == '#') {
      oc++;
      break;
    }
    if (m[i + k][j] == 'L') {
      break;
    }
    k++;
  }
  k = 1;
  while (i + k < m.size() && 0 <= j - k) {
    if (m[i + k][j - k] == '#') {
      oc++;
      break;
    }
    if (m[i + k][j - k] == 'L') {
      break;
    }
    k++;
  }
  k = 1;
  while (0 <= i - k && j + k < m[i].size()) {
    if (m[i - k][j + k] == '#') {
      oc++;
      break;
    }
    if (m[i - k][j + k] == 'L') {
      break;
    }
    k++;
  }
  k = 1;
  while (0 <= i - k) {
    if (m[i - k][j] == '#') {
      oc++;
      break;
    }
    if (m[i - k][j] == 'L') {
      break;
    }
    k++;
  }
  k = 1;
  while (0 <= i - k && 0 <= j - k) {
    if (m[i - k][j - k] == '#') {
      oc++;
      break;
    }
    if (m[i - k][j - k] == 'L') {
      break;
    }
    k++;
  }
  k = 1;
  while (j + k < m[i].size()) {
    if (m[i][j + k] == '#') {
      oc++;
      break;
    }
    if (m[i][j + k] == 'L') {
      break;
    }
    k++;
  }
  k = 1;
  while (0 <= j - k) {
    if (m[i][j - k] == '#') {
      oc++;
      break;
    }
    if (m[i][j - k] == 'L') {
      break;
    }
    k++;
  }
  return oc;
}

long int level2(ifstream &file) {
  vector<string> m;
  string line;
  while (getline(file, line)) {
    m.push_back(line);
  }
  int ch = 1;
  while (ch) {
    ch = 0;
    vector<int> ci, cj;
    for (int i = 0; i < m.size(); i++) {
      for (int j = 0; j < m[i].size(); j++) {
        if (m[i][j] == '.') {
          continue;
        }
        if (m[i][j] == '#') {
          int occ = count_occ2(m, i, j);
          if (occ > 4) {
            cj.push_back(j);
            ci.push_back(i);
          }
        }
        if (m[i][j] == 'L') {
          int occ = count_occ2(m, i, j);
          cout << i << ":" << j << " " << occ << endl;
          if (occ == 0) {
            cj.push_back(j);
            ci.push_back(i);
          }
        }
      }
    }
    ch = cj.size();
    for (int t = 0; t < ch; t++) {
      if (m[ci[t]][cj[t]] == '#') {
        m[ci[t]][cj[t]] = 'L';
      } else if (m[ci[t]][cj[t]] == 'L') {
        m[ci[t]][cj[t]] = '#';
      } else {
        cout << "Ups!" << endl;
      }
    }
    print_m(m);
    cout << endl;
  }
  int out = 0;
  for (int i = 0; i < m.size(); i++) {
    for (int j = 0; j < m[i].size(); j++) {
      if (m[i][j] == '#') {
        out++;
      }
    }
  }
  print_m(m);
  cout << endl;
  return out;
}

int main() {
  ifstream file;
  file.open("input");
  long int out = level2(file);
  cout << endl << "Result: " << out << endl;
}
