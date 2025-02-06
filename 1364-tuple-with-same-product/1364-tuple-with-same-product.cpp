class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int p=nums[i]*nums[j];
                mp[p]++;
            }
        }
        for(auto &it:mp){
            int prod=it.first;
            int freq=it.second;
            ans+=(freq*(freq-1))/2;
        }
        return ans*8;
    }
};