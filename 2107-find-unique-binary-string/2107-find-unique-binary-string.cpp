#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool backtrack(string &s, unordered_set<string>& numSet, vector<char>& vec, int n) {
        if (s.length() == n) {
            if (numSet.find(s) == numSet.end()) { 
                return true;
            }
            return false;
        }
        for (char c : vec) {
            s += c;
            if (backtrack(s, numSet, vec, n)) return true; 
            s.pop_back(); 
        }
        return false;
    }

    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<string> numSet(nums.begin(), nums.end()); 
        string s = "";
        vector<char> vec = {'0', '1'};
        backtrack(s, numSet, vec, nums[0].length()); 
        return s;
    }
};