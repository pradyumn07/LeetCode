class Solution {
public:
    int n;
    int dp[101];
    int solve(int ind,vector<int>& nums){
        if(ind==n) return 0;
        if(ind==n-1) return nums[ind];
        if(dp[ind]!=-1) return dp[ind];
        int take=nums[ind]+solve(ind+2,nums);
        int nottake=0+solve(ind+1,nums);
        return dp[ind]=max(take,nottake);

    }
    int rob(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(0,nums);
    }
};