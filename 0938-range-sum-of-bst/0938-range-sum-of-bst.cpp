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
    int sumnodes(TreeNode* root, int low, int high, int count){
        if(root == NULL){
            return count;
        }
        else if(root->left == NULL && root -> right == NULL && root->val >= low && root->val <=high){
            count +=root->val;
        }
        else if(root->val >= low && root->val <=high){
        count = root->val + sumnodes(root->left,low,high,count) + sumnodes(root->right,low,high,count);
        }
        else{
            count = sumnodes(root->left,low,high,count) + sumnodes(root->right,low,high,count);
        }
        return count;
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        return sumnodes(root,low,high,0);
    }
};