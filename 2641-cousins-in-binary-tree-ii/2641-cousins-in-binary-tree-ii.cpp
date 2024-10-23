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
    TreeNode* replaceValueInTree(TreeNode* root) {
        if(root==NULL) return root;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> level;
        while(!q.empty()){
            int levelSum=0;
            int n=q.size();
                while(n--){
                    TreeNode* node=q.front();
                    q.pop();
                    levelSum+=node->val;
                    if(node->left){
                        q.push(node->left);
                    }
                    if(node->right){
                        q.push(node->right);
                    }
                }
            level.push_back(levelSum);
        }
        
        q.push(root);
        root->val=0;
        int i=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                TreeNode* node=q.front();
                q.pop();
                int sibSum=node->left!=NULL?node->left->val:0;
                sibSum+=node->right!=NULL?node->right->val:0;
                if(node->left){
                    node->left->val=level[i]-sibSum;
                    q.push(node->left);
                }
                if(node->right){
                    node->right->val=level[i]-sibSum;
                    q.push(node->right);
                }
                
            }
            i++;
        }
        return root;
    }
};