class Solution {
public:
    int dp[1001];
    int n;
    int solve(int ind,vector<int>& nums){
        if(ind==0) return nums[ind];
        if(ind<0) return 0;
        if(dp[ind]!=-1) return dp[ind];
        int pick=nums[ind]+solve(ind-2,nums);
        int notpick=solve(ind-1,nums);
        return dp[ind]=max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        memset(dp,-1,sizeof(dp));
        vector<int> temp1(nums.begin() + 1, nums.end()); 
        vector<int> temp2(nums.begin(), nums.end() - 1); 
        int ans1=solve(temp1.size()-1,temp1);
        memset(dp,-1,sizeof(dp));
        int ans2=solve(temp2.size()-1,temp2);
        return max(ans1,ans2);
    }
};