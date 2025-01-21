class Solution {
public:
    int dp[2501][2501];
    int solve(vector<vector<int>>& pairs,int n,int i, int p){
        if(i>=n) return 0;
        int take=0;
        if(p!=-1 && dp[i][p]!=-1) return dp[i][p];
        if(p==-1||pairs[p][1]<pairs[i][0]){
            take=1+solve(pairs,n,i+1,i);
        }
        int skip=solve(pairs,n,i+1,p);
        if(p!=-1) dp[i][p]=max(take,skip);
        return max(take,skip);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        memset(dp,-1,sizeof(dp));
        sort(begin(pairs),end(pairs));
        return solve(pairs,n,0,-1);
    }
};