class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int> mp;
        int ans=0;
        for(int& num:nums) mp[num]++;
        for(int &num:nums){
            int mini=num;
            int maxi=num+1;
            if(mp.count(maxi)) ans=max(ans,mp[mini]+mp[maxi]);

        }
        return ans;
    }
};