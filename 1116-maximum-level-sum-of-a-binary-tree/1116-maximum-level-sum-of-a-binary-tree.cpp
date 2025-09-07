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
    int maxLevelSum(TreeNode* root) {
        if(root==NULL) return 0;
        queue<pair<TreeNode*,int>> q;
        q.push({root,1});
        int maxi=INT_MIN;
        int ans=0;
        while(!q.empty()){
            int size=q.size();
            int sum=0;
            int level;
            for(int i=0;i<size;i++){
                TreeNode* node=q.front().first;
                level=q.front().second;
                q.pop();
                sum+=node->val;
                if(node->left) q.push({node->left,level+1});
                if(node->right) q.push({node->right,level+1});

            }
            if(maxi<sum){
                maxi=sum;
                ans=level;
            }

        }
        return ans;
    }
};