class Solution {
public:
    int n;
    int dp[100001][3][3];
    int solve(int ind,int buy,int cap,vector<int>& prices){
        if(ind == n) return 0;
        if(cap==0) return 0;
        if(dp[ind][buy][cap]!=-1) return dp[ind][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-prices[ind]+solve(ind+1,0,cap,prices),0+solve(ind+1,1,cap,prices));
        } else {
            profit=max(prices[ind]+solve(ind+1,1,cap-1,prices),0+solve(ind+1,0,cap,prices));
        }
        return dp[ind][buy][cap]=profit;
    }
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,1,2,prices);


    }
};