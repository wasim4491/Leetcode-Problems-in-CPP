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
    TreeNode* helper(TreeNode* root, TreeNode* newroot){
        if(root == NULL){
            return NULL;
        }
        if(newroot == NULL){
            newroot = new TreeNode(root->val);
        }
        newroot->right = helper(root->left, newroot->right);
        newroot->left = helper(root->right, newroot->left);
        return newroot;
        
    }
    
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL){
            return NULL;
        }
        TreeNode* newroot = new TreeNode(root->val);
        helper(root, newroot);
        return newroot;
    }
};