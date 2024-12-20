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
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        
        queue<TreeNode*> q;
        q.push(root);
        int level = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<TreeNode*> vec;
            for(int i=0; i<sz; i++){
                TreeNode* temp = q.front();
                if(level % 2 != 0){
                    vec.push_back(temp);
                }
                q.pop();
                
                if(temp->left != NULL){
                    q.push(temp->left);
                    q.push(temp->right);
                }
            }
            level++;
            int l = 0, r = vec.size() - 1;
            while(l < r){
                swap(vec[l]->val, vec[r]->val);
                l++;
                r--;
            }
        }
        return root;
        
    }
};