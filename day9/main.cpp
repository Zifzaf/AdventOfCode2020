#include <fstream>
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;


long int level1(ifstream &file) {
    vector<long int> nums;
    for( int i = 0; i < 25; i++){
        long int k;
        file >> k;
        nums.push_back(k);
    }
    long int next;
    while(!file.eof()){
        file >> next;
        vector<long int> l;
        int i;
        for(i = 0; i < 25; i++){
            if(find(l.begin(), l.end(), nums[i]) != l.end()) {
                break;
            }
            l.push_back(next-nums[i]);
        }
        if(i == 25){
            break;
        }
        nums.erase(nums.begin());
        nums.push_back(next);
    }
    return next;
}

long int level2(ifstream &file) {
    vector<long int> nums;
    while(!file.eof()){
        long int next;
        file >> next;
        nums.push_back(next);
    }
    int i, j, min, max;
    for(i = 0; i < nums.size(); i++){
        int sum = nums[i];
        min = nums[i];
        max = nums[i];
        j = i;
        while(sum < 57195069){
            j++;
            sum += nums[j];
            if(nums[j] < min){
                min = nums[j];
            }
            if(nums[j] > max){
                max = nums[j];
            }
        }
        if(i < j && sum == 57195069){
            break;
        }
    }
    return min + max;
}

int main() {
  ifstream file;
  file.open("input");
  long int out = level2(file);
  cout << endl << "Result: " << out << endl;
}
