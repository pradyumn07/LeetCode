class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int inc=1;
            int j=i+1;
            while(j<n && nums[j]>nums[j-1]){
                inc++;
                j++;
            }
            int dec=1;
            j=i+1;
            while(j<n && nums[j]<nums[j-1]){
                dec++;
                j++;
            }
            ans=max({inc,dec,ans});
        }
        return ans;
    }
};