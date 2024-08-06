class Solution {
public:
    
    long long findWays(vector<vector<int>>& grid,int i,int j,vector<vector<long long>>& dp){
        if(i==0 && j==0) return grid[0][0];
        if(i<0 || j<0) return 1e9;
        if(dp[i][j]!=-1) return dp[i][j];
        long long up=grid[i][j]+findWays(grid,i-1,j,dp);
        long long left=grid[i][j]+findWays(grid,i,j-1,dp);
        return dp[i][j]=min(up,left);
    }
    long long minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<long long>> dp(m,vector<long long>(n,-1));
        return findWays(grid,m-1,n-1,dp);
    }
};