class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0],maxi=nums[0],mini=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]<0) swap(maxi,mini);
            maxi=max(nums[i],maxi*nums[i]);
            mini=min(nums[i],mini*nums[i]);
            ans=max(ans,maxi);
        }
        return ans;
    }
};