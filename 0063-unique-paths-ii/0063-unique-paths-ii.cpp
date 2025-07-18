class Solution {
public:
    int dp[101][101];

    int solve(int i,int j, vector<vector<int>>& obstacleGrid){
        if(i>=0 && j>=0 && obstacleGrid[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int left=solve(i,j-1,obstacleGrid);
        int top=solve(i-1,j,obstacleGrid);
        return dp[i][j]=left+top;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        memset(dp,-1,sizeof(dp));
        return solve(m-1,n-1,obstacleGrid);
    }
};