class Solution {
public:
    // int n;
    // int dp[2502][2502];
    // int solve(int p,int ind,vector<int>& nums){
    //     if(ind>=n) return 0;
    //     if(p!=-1 && dp[ind][p]!=-1) return dp[ind][p];
    //     int take=0;
    //     if(p==-1 || nums[p]<nums[ind]){
    //         take=1+solve(ind,ind+1,nums);
    //     }
    //     int skip=solve(p,ind+1,nums);
    //     if(p!=-1) dp[ind][p]=max(take,skip);
    //     return max(take,skip);
    // }
    int lengthOfLIS(vector<int>& nums) {
        // n=nums.size();

        // memset(dp,-1,sizeof(dp));
        // return solve(-1,0,nums);
        int n=nums.size();
        vector<int> temp;
        temp.push_back(nums[0]);
        int len=1;
        for(int i=1;i<n;i++){
            if(nums[i]>temp.back()){
                len++;
                temp.push_back(nums[i]);
            } else {
                int ind=lower_bound(temp.begin(),temp.end(),nums[i])-temp.begin();
                temp[ind]=nums[i];
            }
        }
        return len;
    }
};