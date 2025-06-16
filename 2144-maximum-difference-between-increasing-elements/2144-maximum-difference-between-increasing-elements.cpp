class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int diff=-1;
        int maxi=INT_MIN;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]<nums[j]) maxi=max(maxi,nums[j]-nums[i]);
                
            }
            
        }
        if(maxi!=INT_MIN) return maxi;
        return -1;
    }
};