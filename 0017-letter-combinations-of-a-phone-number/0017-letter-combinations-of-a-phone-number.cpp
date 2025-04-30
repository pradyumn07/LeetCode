class Solution {
public:
    void back(string &digits, int ind, string &curr,unordered_map<char, string> &mp, vector<string> &ans){
        if(ind==digits.size()){
            ans.push_back(curr);
            return;
        }
        string letter=mp[digits[ind]];
        for(char l:letter){
            curr.push_back(l);
            back(digits,ind+1,curr,mp,ans);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        unordered_map<char, string> mp = {
            {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
        };
        vector<string> ans;
        string curr;
        back(digits,0,curr,mp,ans);
        return ans;
    }


};