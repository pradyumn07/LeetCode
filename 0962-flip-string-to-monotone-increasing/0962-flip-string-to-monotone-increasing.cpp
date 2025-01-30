class Solution {
public:
    int n;
    
    int solve(string &s,int curr,int prev,vector<vector<int>> &dp){
        if(curr>=n) return 0;
        if(dp[curr][prev]!=-1) return dp[curr][prev];
        int flip=INT_MAX;
        int noflip=INT_MAX;
        if(s[curr]=='0'){
            if(prev==0){
                flip=1+solve(s,curr+1,1,dp);
                noflip=solve(s,curr+1,0,dp);
            }
            else{
                flip=1+solve(s,curr+1,1,dp);
            }
        }
        else if(s[curr]=='1'){
            if(prev==1){
                noflip=solve(s,curr+1,1,dp);
            } else {
                flip=1+solve(s,curr+1,0,dp);
                noflip=solve(s,curr+1,1,dp);
            }
        }
        return dp[curr][prev]=min(flip,noflip);
    }
    int minFlipsMonoIncr(string s) {
        n=s.length();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return solve(s,0,0,dp);
    }
};