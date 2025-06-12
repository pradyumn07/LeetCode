class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n=nums.size();
        int maxi=INT_MIN;
        int diff;
        for(int i=1;i<=n;i++){
            if(i!=n) diff=abs(nums[i]-nums[i-1]);
            if(i==n) diff=abs(nums[n-1]-nums[0]);
            maxi=max(maxi,diff);
        }
        return maxi;
    }
};