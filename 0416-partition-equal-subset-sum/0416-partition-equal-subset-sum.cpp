class Solution {
public:
    int dp[202][20002];
    bool solve(int ind,int target,vector<int>& nums){
        if(ind>0 && target==0) return true;
        if(ind==0) return nums[ind]==target;
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool take=false;
        if(target>=nums[ind]) take=solve(ind-1,target-nums[ind],nums);
        bool nottake=solve(ind-1,target,nums);
        return dp[ind][target]=take|nottake;
        
    }
    bool canPartition(vector<int>& nums) {
        int total=accumulate(nums.begin(),nums.end(),0);
        int target;
        if(total%2!=0) return false;
        else {
            target=total/2;
        }
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        return solve(n-1,target,nums);
        // vector<vector<bool>> dp(n,vector<bool>(target+1,false));
        
        // for(int i=0;i<n;i++) dp[i][0]=true;
        // if(nums[0]<=target) dp[0][nums[0]]=true;
        // for(int i=1;i<n;i++){
        //     for(int j=1;j<=target;j++){
        //         bool nottake=dp[i-1][j];
        //         bool take=false;
        //         if(nums[i]<=j){
        //             take=dp[i-1][j-nums[i]];
        //         }
        //         dp[i][j]=take || nottake;
        //     }
        // }
        // return dp[n-1][target];
    }
};