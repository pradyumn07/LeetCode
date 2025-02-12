class Solution {
public:
    int solve(int num){
        int i=num;
        int s=0;
        while(i>0){
            int r=i%10;
            s+=r;
            i=i/10;
        }
        return s;
    }
    int maximumSum(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            int sum=solve(nums[i]);
            if(mp.count(sum)){
                ans=max(ans,nums[i]+mp[sum]);
            }
            mp[sum]=max(mp[sum],nums[i]);
        }
        return ans;
    }
};