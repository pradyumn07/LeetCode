class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        long long ans=0;
        unordered_map<int,int> mp;
        long long p=0;
        while(j<n){
            p+=mp[nums[j]];
            mp[nums[j]]++;
            while(p>=k){
                ans+=(n-j);
                mp[nums[i]]--;
                p-=mp[nums[i]];
                i++;
            }
            j++;
        }
        return ans;
    }
};