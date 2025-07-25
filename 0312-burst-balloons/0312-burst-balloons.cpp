class Solution {
public:
    int dp[301][301];
    int solve(int i,int j,vector<int>& nums){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int maxi=INT_MIN;
        for(int k=i;k<=j;k++){
            int cost=nums[i-1]*nums[k]*nums[j+1]+solve(i,k-1,nums)+solve(k+1,j,nums);
            maxi=max(maxi,cost);
        }
        return dp[i][j]=maxi;
    }
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        memset(dp,-1,sizeof(dp));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        return solve(1,n,nums);
    }
};