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
        int level, maxisum = INT_MIN;
        queue<TreeNode* > q;
        q.push(root);
        int leveltemp = 0;
        while(!q.empty()){
            leveltemp++;
            int sz = q.size();
            int count = 0;
            for(int i=0;i<sz;i++){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                count += temp -> val;
            }
            if(maxisum < count){
                maxisum = count;
                level = leveltemp;
            }
        }
        return level;
    }
};