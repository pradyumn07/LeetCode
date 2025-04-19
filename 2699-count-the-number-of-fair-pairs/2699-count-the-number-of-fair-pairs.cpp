class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        int n=nums.size();
        sort(begin(nums),end(nums));
        long long ans=0;
        for(int i=0;i<n;i++){
            int idx=lower_bound(begin(nums)+i+1,end(nums),lower-nums[i])-begin(nums);
            int x=idx-1-i;
            int index=upper_bound(begin(nums)+i+1,end(nums),upper-nums[i])-begin(nums);
            int y=index-1-i;
            ans+=(y-x);
        }
        return ans;
    }
};