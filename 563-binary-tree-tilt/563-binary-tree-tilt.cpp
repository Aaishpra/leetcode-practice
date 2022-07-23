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
    int total=0;
    int solve(TreeNode* root){
        if(!root) return 0;
        int lsum=solve(root->left);
        int rsum=solve(root->right);
        total+=abs(lsum-rsum);
        return lsum+rsum+root->val;
    }
    int findTilt(TreeNode* root) {
        solve(root);
        return total;
    }
};