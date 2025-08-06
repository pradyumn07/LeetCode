class Solution {
public:
    int jump(vector<int>& nums) {
        int maxreach,l=0,r=0;
        int jump=0;
        int n=nums.size();
        while(r<n-1){
            maxreach=0;
            for(int i=l;i<=r;i++){
                maxreach=max(maxreach,i+nums[i]);
            }
            l=r+1;
            r=maxreach;
            jump++;
        }
        return jump;
    }
};