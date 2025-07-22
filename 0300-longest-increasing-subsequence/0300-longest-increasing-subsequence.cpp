class Solution {
public:
    
    int dp[2501][2501];
    int solve(vector<int>& nums,int n,int i, int p){
        if(i>=n) return 0;
        int take=0;
        if(p!=-1 && dp[i][p]!=-1) return dp[i][p];
        if(p==-1||nums[p]<nums[i]){
            take=1+solve(nums,n,i+1,i);
        }
        int skip=solve(nums,n,i+1,p);
        if(p!=-1) dp[i][p]=max(take,skip);
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,n,0,-1);
         
    }
};