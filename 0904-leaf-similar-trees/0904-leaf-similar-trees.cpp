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
    void solve(TreeNode* root1,vector<int> &temp1){
        if(root1==NULL) return;
        if(root1->left==NULL && root1->right==NULL) temp1.push_back(root1->val);
        solve(root1->left,temp1);
        solve(root1->right,temp1);
    }
    void solve2(TreeNode* root2,vector<int> &temp2){
        if(root2==NULL) return;
        if(root2->left==NULL && root2->right==NULL) temp2.push_back(root2->val);
        solve(root2->left,temp2);
        solve(root2->right,temp2);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> temp1,temp2;
        solve(root1,temp1);
        solve2(root2,temp2);
        if(temp1.size()!=temp2.size()) return false;
        int i=0;
        while(i<temp1.size()){
            if(temp1[i]!=temp2[i]) return false;
            i++;
        }
        return true;
    }
};