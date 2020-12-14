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
    while(!file.eof()){
        long int next;
        file >> next;
        nums.push_back(next);
    }
    sort(nums.begin(),nums.end());
    int prev = 0,diff1 = 0,diff2 = 0,diff3 = 0, curr;
    for(int i = 0; i < nums.size();i++){
        curr = nums[i];
        if(curr - prev == 1){
            diff1++;
        }
        if(curr - prev == 2){
            diff2++;
        }
        if(curr - prev == 3){
            diff3++;
        }
        if(curr - prev > 3){
            cout << "Ups!" << endl;
        }
        prev = curr;
    }
    diff3++;
    return diff3 * diff1;
}

long int count_ways(vector<long int> nums, int i, vector<long int> &mem){
    if(i == nums.size() - 1){
        return 1;
    }
    long int curr;
    if( i < 0){
        curr = 0;
    } else {
        curr = nums[i];
    }
    long int sum = 0;
    for(int t = i + 1; t < i + 4; t++){
        if(t < nums.size()){
            if(nums[t] - curr < 4){
                if(mem[t]){
                    sum += mem[t];
                } else {
                    long int ret = count_ways(nums,t,mem);
                    mem[t] = ret;
                    sum += mem[t];
                }
            }
        }
    }
    return sum;
}

long int level2(ifstream &file) {
    vector<long int> nums;
    while(!file.eof()){
        long int next;
        file >> next;
        nums.push_back(next);
    }
    nums.pop_back();
    for(int i = 0; i < nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    sort(nums.begin(),nums.end());
    for(int i = 0; i < nums.size();i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    vector<long int> mem (nums.size());
    return count_ways(nums,-1,mem);
}

int main() {
  ifstream file;
  file.open("input");
  long int out = level2(file);
  cout << endl << "Result: " << out << endl;
}
