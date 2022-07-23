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
    bool isSym(TreeNode* p,TreeNode* q){
        if(p==NULL or q==NULL) return p==q;
        return p->val==q->val and isSym(p->left,q->right) and isSym(p->right,q->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSym(root->left,root->right);
    }
};