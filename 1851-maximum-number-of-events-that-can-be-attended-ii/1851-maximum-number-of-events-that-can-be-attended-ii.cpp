class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<vector<int>>& events,int i,int k){
        if(i>=n || k==0) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        int start=events[i][0];
        int end=events[i][1];
        int value=events[i][2];
        int skip=solve(events,i+1,k);
        int j=i+1;
        for(;j<n;j++){
            if(events[j][0]>events[i][1]) break;
        } 
        int take=value+solve(events,j,k-1);
        return dp[i][k]=max(take,skip);
    }
    int maxValue(vector<vector<int>>& events, int k) {
        n=events.size();
        dp.resize(n+1,vector<int>(k+1,-1));
        sort(begin(events),end(events));
        return solve(events,0,k);
    }
};