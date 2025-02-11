class Solution {
public:
    int m,n;
    int dp[1001][1001];
    const int mod=1e9+7;
    vector<vector<int>> direc={{-1,0},{0,-1},{0,1},{1,0}};
    int solve(vector<vector<int>>& grid,int i,int j){
        int result=1;
        if(dp[i][j]!=-1) return dp[i][j];
        for(auto &dir:direc){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            if(new_i<m && new_i>=0 && new_j<n && new_j>=0 && grid[new_i][new_j]<grid[i][j]){
                result=(result+solve(grid,new_i,new_j))%mod;
            }
        }
        return dp[i][j]=result;

    }
    int countPaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=(ans+solve(grid,i,j))%mod;
            }
        }
        return ans;
    }
};