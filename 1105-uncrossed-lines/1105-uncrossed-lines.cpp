class Solution {
public:
    int n,m;
    int dp[501][501];
    int solve(vector<int> &nums1,vector<int> &nums2,int i,int j){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i]==nums2[j]){
             return dp[i][j]=1+solve(nums1,nums2,i+1,j+1);
        }
        else{
            int change_i=solve(nums1,nums2,i+1,j);
            int change_j=solve(nums1,nums2,i,j+1);
            return dp[i][j]=max(change_i,change_j);

        }
        
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        memset(dp,-1,sizeof(dp));
        return solve(nums1,nums2,0,0);
    }
};