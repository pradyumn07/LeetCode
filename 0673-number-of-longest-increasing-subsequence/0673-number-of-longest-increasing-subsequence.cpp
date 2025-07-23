class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> count(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    count[i]=count[j];
                } else if(nums[j]<nums[i] && 1+dp[j]==dp[i]){
                    count[i]+=count[j];
                }
            }
            maxi=max(maxi,dp[i]);
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(dp[i]==maxi) cnt+=count[i];
        }
        return cnt;
    
    }
};