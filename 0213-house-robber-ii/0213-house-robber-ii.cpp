class Solution {
public:
    int t[101];
    int findWays(int n, vector<int>& nums, int i) {
        if (i >= n) return 0; 
        if (t[i]!=-1) return t[i];
        int rob=nums[i]+findWays(n,nums,i+2); 
        int skip=findWays(n,nums,i+1);         
        return t[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
        int n=nums.size();
        if (n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]);
        memset(t, -1, sizeof(t));
        int robFirst =findWays(n-1,nums,0); 
        memset(t,-1,sizeof(t));
        int robSecond =findWays(n,nums,1); 
        return max(robFirst,robSecond); 
    }
};
