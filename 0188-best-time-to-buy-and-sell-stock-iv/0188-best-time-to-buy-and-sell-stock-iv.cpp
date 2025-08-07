class Solution {
public:
    int n;
    
    int solve(int ind,int buy,int cap,vector<int>& prices, vector<vector<vector<int>>>& dp){
        if(ind == n) return 0;
        if(cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+solve(ind+1,0,cap,prices,dp),0+solve(ind+1,1,cap,prices,dp));
        } else {
            profit=max(prices[ind]+solve(ind+1,1,cap-1,prices,dp),0+solve(ind+1,0,cap,prices,dp));
        }
        return dp[ind][buy][cap]=profit;
    }

    int maxProfit(int k, vector<int>& prices) {
        n=prices.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(k + 1, -1)));

        // memset(dp,-1,sizeof(dp));
        return solve(0,1,k,prices,dp);
    }
};