class Solution {
public:
    int n;
    int solve(vector<int>& nums,vector<bool>& vis,int op,unordered_map<vector<bool>,int>& mp){
        int maxScore=0;
        if(mp.find(vis)!=mp.end()) return mp[vis];
        for(int i=0;i<n-1;i++){
            if(vis[i]==true) continue;
            for(int j=i+1;j<n;j++){
                if(vis[j]==true) continue;
                vis[i]=true;
                vis[j]=true;
                int curr=op*__gcd(nums[i],nums[j]);
                int remain=solve(nums,vis,op+1,mp);
                maxScore=max(maxScore,curr+remain);
                vis[i]=false;
                vis[j]=false;
            }
        }
        return mp[vis]=maxScore;
    }
    int maxScore(vector<int>& nums) {
        n=nums.size();
        vector<bool> vis(n,false);
        unordered_map<vector<bool>,int> mp;
        return solve(nums,vis,1,mp);
    }
};