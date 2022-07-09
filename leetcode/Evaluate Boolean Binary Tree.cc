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
    bool evaluateTree(TreeNode* root) {
        if(!root) return 0;
        if(root->val==2){
            bool x = evaluateTree(root->left);
            bool y = evaluateTree(root->right);
            return x||y;
        }
        if(root->val==3){
            bool x = evaluateTree(root->left);
            bool y = evaluateTree(root->right);
            return x&&y;
        }
        return root->val;
    }
};
