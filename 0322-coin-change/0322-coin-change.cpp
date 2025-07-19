class Solution {
public:
    int n;
    int dp[13][10001];
    int solve(int ind,int target,vector<int>& coins){
        if(target==0) return 0;
        if(ind==0){
            if(target%coins[ind]==0) return target/coins[ind];
            else return 1e9;
        }
        if(dp[ind][target]!=-1) return dp[ind][target];
        int notpick=solve(ind-1,target,coins);
        int pick=INT_MAX;
        if(target>=coins[ind]) pick=1+solve(ind,target-coins[ind],coins);
        return dp[ind][target]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        n=coins.size();
        sort(coins.begin(),coins.end());
        memset(dp,-1,sizeof(dp));
        int ans= solve(n-1,amount,coins);
        return ans!=1e9?ans:-1;        
    }
};