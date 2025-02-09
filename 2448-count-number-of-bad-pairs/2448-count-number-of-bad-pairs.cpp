class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]-i;
        }
        mp[nums[0]]=1;
        for(int j=1;j<n;j++){
            int countj=mp[nums[j]];
            int totalnopass=j;
            int bad=totalnopass-countj;
            ans+=bad;
            mp[nums[j]]++;
        }
        return ans;
    }
};