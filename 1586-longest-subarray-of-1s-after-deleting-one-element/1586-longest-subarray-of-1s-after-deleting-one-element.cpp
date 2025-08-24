class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l=0,r=0;
        int maxi=INT_MIN;
        int k=0;
        while(r<nums.size()){
            if(nums[r]!=1) k++;
            while(k>1){
                if(nums[l]!=1) k--;
                l++;
            }
            maxi=max(maxi,r-l);
            r++;
        }
        return maxi;
    }
};