class Solution {
public:
    int n;
    int dp[21][2001];
    int solve(vector<int> &nums,int target,int i){
        if(target<-1000 || target>1000) return 0;
        if(i>=n){
            if(target==0) return 1;
            else return 0;

        }
        if(dp[i][target+1000]!=-1) return dp[i][target+1000];
        int diff=solve(nums,target+(-1)*nums[i],i+1);
        int sum=solve(nums,target+nums[i],i+1);
        return dp[i][target+1000]=diff+sum;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums,target,0);

    }
};