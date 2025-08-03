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
    void solve(TreeNode* root,map<int,int>& mp){
        if(root==NULL) return;
        mp[root->val]++;
        solve(root->left,mp);
        solve(root->right,mp);
    }
    bool findTarget(TreeNode* root, int k) {
        map<int,int> mp;
        if(root==NULL) return false;
        if(root->left==NULL && root->right==NULL) return false;
        solve(root,mp);
        for(auto &it:mp){
            int diff=k-it.first;
            mp.erase(it.first);
            if(mp.find(diff)!=mp.end()) return true;
        }
        return false;
    }
};