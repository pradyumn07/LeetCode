class Solution {
public:
    bool compare(string &word1,string &word2){
        if(word1.size()!=word2.size()+1) return false;
        int f1=0;
        int f2=0;
        while(f1<word1.size()){
            if(word1[f1]==word2[f2]){
                f1++;
                f2++;
            } else {
                f1++;
            }
        }
        if(f1==word1.size() && f2==word2.size()) return true;
        return false;
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string &a, string &b) {
            return a.size() < b.size();  // Sort by increasing length
        });
        int maxi=0;
        int n=words.size();
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(compare(words[i],words[j]) && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};