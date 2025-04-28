class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n=nums.size();
        int i=0,j=0;
        long long ans=0;
        long long sum=0;
        long long len=0;
        while(j<n){
            sum+=nums[j];
            len++;
            while(sum*len>=k){
                sum-=nums[i];
                i++;
                len--;
            }
            ans+=len;
            j++;
        }
        return ans;
    }
};