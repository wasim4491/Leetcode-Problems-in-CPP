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
    void ans(TreeNode* root, vector<int> &result){
         if(root == NULL){
             return;
         }
        ans(root->left, result);
        result.push_back(root->val);
        ans(root->right, result);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> result;
         ans(root,result);
        int mini = INT_MAX;
        for(int i=0;i<result.size()-1;i++){
            int temp = abs(result[i] - result[i+1]);
            if(temp < mini){
                mini = temp;
            }
        }
        return mini;
    }
};