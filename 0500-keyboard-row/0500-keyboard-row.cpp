class Solution {
public:
    bool solve(string s1,string s2){
        for(int i=0;i<s1.length();i++){
            int f=0;
            for(int j=0;j<s2.length();j++){
                if(s1[i]==s2[j]) f=1;
                else continue;
            }
            if(f==0) return false;
        }
        return true;
    }
    vector<string> findWords(vector<string>& words) {
        vector<string> keyboard={"qwertyuiopQWERTYUIOP","asdfghjklASDFGHJKL","zxcvbnmZXCVBNM"};
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            if(solve(words[i],keyboard[0]) || solve(words[i],keyboard[1]) ||solve(words[i],keyboard[2])) ans.push_back(words[i]);
        }
        return ans;
    }
};
