class Solution {
public:
    int jump(vector<int>& nums) {
        int l=0,r=0,jumps=0;
        int n=nums.size();
        while(r<n-1){
            int maxreach=0;
            for(int i=l;i<=r;i++){
                maxreach=max(maxreach,i+nums[i]);
            }
            l=r+1;
            r=maxreach;
            jumps++;
        }
        return jumps;
    }
};