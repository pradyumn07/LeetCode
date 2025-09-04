class Solution {
public:
    long long maxarray(vector<int>& nums,int goal){
        if(goal<0) return 0;
        int n=nums.size();
        int l=0,r=0;
        long long ans=0;
        long long sum=0;
        while(r<n){
            sum+=nums[r];
            while(l<n && sum>goal){
                sum=sum-nums[l];
                l++;
            }
            ans=ans+(r-l+1);
            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return maxarray(nums,goal)-maxarray(nums,goal-1);
    }
};