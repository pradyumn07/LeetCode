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
    void solve(TreeNode* root,int &c,vector<int>& ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        int maxi=*max_element(ans.begin(),ans.end());
        if(maxi==root->val) c++;
        solve(root->left,c,ans);

        solve(root->right,c,ans);
        ans.pop_back();
    }
    int goodNodes(TreeNode* root) {
        vector<int> ans;
        int c=0;
        solve(root,c,ans);
        return c;
    }
};