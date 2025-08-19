class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int i=0,j=0;
        while(j<nums.size()){
            if(nums[j]==0){
                j++;
                continue;
            }
            ans+=(long long)(1LL*(j-i)*(j-i+1)/2);
            j++;
            i=j;
            
        }
        ans+=(long long)(1LL*(j-i)*(j-i+1)/2);
        return ans;
    }
};