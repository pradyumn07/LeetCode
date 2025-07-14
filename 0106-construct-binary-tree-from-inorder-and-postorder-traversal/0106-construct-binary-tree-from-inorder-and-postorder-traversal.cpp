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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()) return NULL;
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        return buildTree(inorder, 0, inorder.size() - 1,
                         postorder, 0, postorder.size() - 1, mp);
    }
    TreeNode* buildTree(vector<int>& inorder, int is, int ie,
                        vector<int>& postorder, int ps, int pe,
                        unordered_map<int, int>& mp) {
        if (ps > pe || is > ie) return nullptr;

        TreeNode* root = new TreeNode(postorder[pe]);
        int inRoot = mp[root->val];
        int numsLeft = inRoot - is;

        root->left = buildTree(inorder, is, inRoot-1,
                               postorder, ps, ps+numsLeft - 1, mp);

        root->right = buildTree(inorder, inRoot + 1, ie,
                                postorder, ps + numsLeft, pe - 1, mp);

        return root;
    }
};