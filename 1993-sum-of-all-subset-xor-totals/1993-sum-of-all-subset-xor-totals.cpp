class Solution {
public:
    void dfs(vector<int>& nums,int i,int curr,int &ans){
        if(i==nums.size()){
            ans+=curr;
            return;
        }
        dfs(nums,i+1,curr^nums[i],ans);
        dfs(nums,i+1,curr,ans);
    }
    int subsetXORSum(vector<int>& nums) {
        int ans=0;
        dfs(nums,0,0,ans);
        return ans;
    }
};