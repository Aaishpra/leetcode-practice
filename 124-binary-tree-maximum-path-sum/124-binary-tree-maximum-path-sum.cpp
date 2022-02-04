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
    int help(TreeNode* root,int &maxe){
        if(root==NULL)return 0;
        int lh=max(0,help(root->left,maxe));
        int rh=max(0,help(root->right,maxe));
        maxe=max(maxe,lh+rh+root->val);
        return max(lh,rh)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        int maxe=INT_MIN;
        help(root,maxe);
        return maxe;
    }
};