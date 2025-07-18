class Solution {
public:
    // int dp[101][101];
    // int solve(int i,int j){
    //     if(i==0 && j==0) return 1;
    //     if(i<0 || j<0) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     int left=solve(i,j-1);
    //     int top=solve(i-1,j);
    //     return dp[i][j]=top+left;
    // }
    int uniquePaths(int m, int n) {
        // memset(dp,-1,sizeof(dp));
        // return solve(m-1,n-1);
        vector<vector<int>> dp(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[0][0]=1;
                else {
                    int left=0,top=0;
                    if(j>0) left=dp[i][j-1];
                    if(i>0) top=dp[i-1][j];
                    dp[i][j]=top+left;
                }
            }
        }
        return dp[m-1][n-1];
    }
};