class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        vector<string> ans;
        if(n==1) return words;
        for(int i=0;i<n;i++){
            if(i==0) ans.push_back(words[i]);
            for(int j=i+1;j<n;j++){
                if(groups[i]!=groups[j]){
                // if(i!=0) ans.push_back(words[i]);
                ans.push_back(words[j]);
                i=j-1;
                break;
            }
            }
        }
        return ans;
    }
};