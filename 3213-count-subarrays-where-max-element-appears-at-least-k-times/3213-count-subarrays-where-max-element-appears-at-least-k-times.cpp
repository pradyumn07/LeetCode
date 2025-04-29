class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(maxi<nums[i]) maxi=nums[i];
        }
        long long ans=0;
        int i=0,j=0;
        unordered_map<int,int> mp;
        while(j<n){
            mp[nums[j]]++;
            while(mp[maxi]>=k){
                ans+=n-j;
                mp[nums[i]]--;
                i++;
            }
            
            j++;
        }
        return ans;

    }
};