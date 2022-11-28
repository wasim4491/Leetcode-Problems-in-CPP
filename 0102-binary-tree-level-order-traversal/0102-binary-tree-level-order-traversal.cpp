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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }
        queue<TreeNode*> res;
        res.push(root);
        while(!res.empty()){
            vector<int> temparr;
            int n = res.size();
            for(int i=0;i<n;i++){
                TreeNode* temp = res.front();
                res.pop();
               // cout << temp->val << " ";
                if(temp->left != NULL){
                   res.push(temp->left); 
                }
                if(temp->right != NULL){
                    res.push(temp->right);
                }
                temparr.push_back(temp->val);
            }
            ans.push_back(temparr);
        }
        return ans;
    }
};