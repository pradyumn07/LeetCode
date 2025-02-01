class Solution {
public:
    int n;
    int dp[501][501];
    int solve(vector<int>& satisfaction,int i,int t){
        if(i>=n) return 0;
        if(dp[i][t]!=-1) return dp[i][t];
        int take=t*satisfaction[i]+solve(satisfaction,i+1,t+1);
        int not_take=solve(satisfaction,i+1,t);
        return dp[i][t]=max(take,not_take);

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        n=satisfaction.size();
        memset(dp,-1,sizeof(dp));
        sort(begin(satisfaction),end(satisfaction));
        return solve(satisfaction,0,1);
    }
};