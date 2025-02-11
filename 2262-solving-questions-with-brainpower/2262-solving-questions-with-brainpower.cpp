class Solution {
public:
    int n;
    long long dp[100001];
    long long solve(vector<vector<int>>& questions,int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        long long take=questions[i][0]+solve(questions,i+questions[i][1]+1);
        long long not_take=solve(questions,i+1);
        return dp[i]=max(take,not_take);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n=questions.size();
        memset(dp,-1,sizeof(dp));
        return solve(questions,0);
    }
};