class Solution {
public:
    int dp[105][105];
    int solve(int i,int j,vector<int>& cuts){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=INT_MAX;
        for(int k=i;k<=j;k++){
            int cost=cuts[j+1]-cuts[i-1]+solve(i,k-1,cuts)+solve(k+1,j,cuts);
            mini=min(mini,cost);

        }
        return dp[i][j]=mini;
    }
    int minCost(int n, vector<int>& cuts) {
        int c=cuts.size();
        memset(dp,-1,sizeof(dp));
        cuts.push_back(n);
        cuts.insert(cuts.begin(),0);
        sort(cuts.begin(),cuts.end());
        return solve(1,c,cuts);
    }
};