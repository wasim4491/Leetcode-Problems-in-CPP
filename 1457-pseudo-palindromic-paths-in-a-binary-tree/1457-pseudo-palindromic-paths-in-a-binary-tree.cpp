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
    bool checkpal(vector<int> pal){
        int oddcount = 0;
        for(int i=0; i<9; i++){
            if(pal[i] % 2 != 0){
                oddcount++;
            }
        }
        if(oddcount > 1){
            return false;
        }
        return true;
    }
    void helper(TreeNode* root, int &count, vector<int> pal){
        if(root == NULL){
            return;
        }
        pal[root->val - 1]++;
        if(root->left == NULL && root->right == NULL){
            if(checkpal(pal)){
                count++;
            }
            return;
        }
        //traverse left
        helper(root->left, count, pal);
        
        //traverse right
        helper(root->right, count, pal);
        
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        int count = 0;
        vector<int> pal(9,0);
        helper(root, count, pal);
        return count;
    }
};