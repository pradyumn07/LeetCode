class Solution {
public:
    int n;
    int dp[301][5001];
    int solve(vector<int> &coins,int amount,int ind){
        if(amount==0) return 1;
        if(ind<0){
            return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTake=solve(coins,amount,ind-1);
        int take=0;
        if(amount>=coins[ind]) take=solve(coins,amount-coins[ind],ind);
        return dp[ind][amount]=notTake+take;
        
    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        memset(dp,-1,sizeof(dp));
        return solve(coins,amount,n-1);
    }
};