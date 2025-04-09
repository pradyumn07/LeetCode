class Solution {
public:
    int dp[5001][2];
    int solve(int i,int buy,vector<int> &prices){
        if(prices.size()<=i) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1){
            return dp[i][buy]=max(-prices[i]+solve(i+1,0,prices),solve(i+1,1,prices));
        } else {
        return dp[i][buy]=max(prices[i]+solve(i+2,1,prices),solve(i+1,0,prices));
        }
    }
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,prices);
    }
};