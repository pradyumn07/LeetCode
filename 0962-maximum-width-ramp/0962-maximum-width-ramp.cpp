class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n=nums.size();
        vector<int> maxToRight(n);
        maxToRight[n-1]=nums[n-1];
        
        for(int i=n-2;i>=0;i--){
            maxToRight[i]=max(maxToRight[i+1],nums[i]);
        }
        int ramp=0,i=0,j=0;
        while(j<n){
            while(i<j && nums[i]>maxToRight[j]){
                i++;
            }
            ramp=max(ramp,j-i);
            j++;
        }
        return ramp;
    }
};