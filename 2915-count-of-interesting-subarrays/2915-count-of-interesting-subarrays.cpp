class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        unordered_map<int,long long> mp;
        mp[0]=1;
        long long c=0,ans=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%modulo==k) c++;
            c=c%modulo;
            int p=(c-k+modulo)%modulo;
            if(mp.find(p)!=mp.end()) ans+=mp[p];
            mp[(int)c]++;  
        }
        return ans;
        
    }
};