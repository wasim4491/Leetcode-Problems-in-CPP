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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q == NULL){
            return true;
        }
        if(p == NULL || q == NULL){
            return false;
        }
        if(p->val != q->val){
            return false;
        }
        bool a = isSameTree(p->left, q->left);
        bool b = isSameTree(p->right, q->right);
        
        return a && b;
    }
    void find(TreeNode* root, TreeNode* subRoot, bool &flag){
        if(root == NULL){
            return;
        }
        if(root->val == subRoot->val){
            // temp = root;
            bool a = isSameTree(root,subRoot);
            if(a == true){
                flag = true;
                return;
            }
        }
        find(root->left, subRoot, flag);
        find(root->right, subRoot, flag);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        // TreeNode* temp = NULL;
        // TreeNode* temp1 = root;
        bool flag = false;
        find(root, subRoot, flag);
        // if(temp == NULL){
        //     return false;
        // }
        return flag;
    }
};