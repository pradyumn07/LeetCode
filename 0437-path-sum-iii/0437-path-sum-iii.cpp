/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    unordered_map<long long,int> mp;
    int ans=0;
    void dfs(TreeNode* root,long long sum,int target){
        if(!root) return;
        sum+=root->val;
        long long rem=sum-target;
        if(mp.find(rem)!=mp.end()) ans+=mp[rem];
        mp[sum]++;
        dfs(root->left,sum,target);
        dfs(root->right,sum,target);
        mp[sum]--;
        if(mp[sum]==0) mp.erase(sum);
    }
    int pathSum(TreeNode* root, int targetSum) {
        mp[0]=1;
        dfs(root,0,targetSum);
        return ans;
    }
};