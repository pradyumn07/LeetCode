class Solution {
public:
    int dp[50001][2];
    int solve(int i,int buy,vector<int> &prices,int fee){
        if(prices.size()<=i) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1){
            return dp[i][buy]=max(-prices[i]+solve(i+1,0,prices,fee),solve(i+1,1,prices,fee));
        }
        return dp[i][buy]=max((prices[i]-fee)+solve(i+1,1,prices,fee),solve(i+1,0,prices,fee));
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,prices,fee);
    }
};