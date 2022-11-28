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
    bool result(TreeNode* leftroot, TreeNode* rightroot){
        if(leftroot == NULL && rightroot == NULL){
            return true;
        }
        if(leftroot && rightroot && leftroot->val == rightroot->val){
            return result(leftroot->left,rightroot->right) && result(leftroot->right,rightroot->left);;
        }
        return false;
    }
    bool isSymmetric(TreeNode* root) {
        return result(root,root);
    }
};