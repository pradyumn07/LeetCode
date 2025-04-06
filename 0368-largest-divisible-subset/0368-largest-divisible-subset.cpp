class Solution {
public:
    // int dp[1001][1001];
    // void solve(int i,vector<int> &nums,vector<int> &ans,vector<int> &temp,int prev){
    //     if(i>=nums.size()){
    //         if(temp.size()>ans.size()){
    //             ans=temp;
    //         }
    //         return;
    //     }
    //     if(dp[i][prev]!=-1) return dp[i][prev];
    //     if(prev==-1 || nums[i]%prev==0){
    //         temp.push_back(nums[i]);
    //         solve(i+1,nums,ans,temp,nums[i]);
    //         temp.pop_back();
    //     }
    //     solve(i+1,nums,ans,temp,prev);
    // }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        sort(begin(nums),end(nums));
        vector<int> dp(n,1);
        vector<int> prev(n,-1);
        int last=0,maxi=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                    }
                
                if(dp[i]>maxi){
                    maxi=dp[i];
                    last=i;
                }
                }
            }
        }
        while(last!=-1){
            ans.push_back(nums[last]);
            last=prev[last];
        }
        return ans;
    }
};