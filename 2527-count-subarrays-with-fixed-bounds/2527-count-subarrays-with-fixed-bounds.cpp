class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        long long ans=0;
        int mini=-1;
        int maxi=-1;
        int bad=-1;
        for(int i=0;i<n;i++){
            if(nums[i]<minK || nums[i]>maxK) bad=i;
            if(nums[i]==minK) mini=i;
            if(nums[i]==maxK) maxi=i;
            int small=min(mini,maxi);
            ans+=max(0,small-bad);
        }
        return ans;
    }
};