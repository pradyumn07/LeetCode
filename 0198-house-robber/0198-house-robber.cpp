class Solution {
public:
    int dp[401];
    int solve(int ind,vector<int>& nums){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+solve(ind-2,nums);
        int notpick=0+solve(ind-1,nums);
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,nums);
    }
};