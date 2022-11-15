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
    int countcomp(TreeNode* root, int count){
        if(root == NULL){
            return 0;
        }
        if(root->left == NULL && root->right == NULL){
            return 1;
        }
        int count1 = countcomp(root->left, count);
        int count2 = countcomp(root->right, count);
        return count1+count2+1;
    }
    int countNodes(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int cnt = 1;
        return countcomp(root,cnt);
    }
};