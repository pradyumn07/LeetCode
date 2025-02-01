class Solution {
public:
    int n;
    int dp[1001][2001];
    int solve(vector<vector<int>>& piles,int i,int k){
        if(i>=n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int not_take=solve(piles,i+1,k);
        int take=0;
        int sum=0;
        for(int j=0;j<min((int)piles[i].size(),k);j++){
            sum+=piles[i][j];
            take=max(take,sum+solve(piles,i+1,k-(j+1)));
        }
        return dp[i][k]=max(not_take,take);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n=piles.size();
        memset(dp,-1,sizeof(dp));
        return solve(piles,0,k);
    }
};