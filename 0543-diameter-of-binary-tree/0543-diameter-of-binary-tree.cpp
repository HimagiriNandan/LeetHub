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
    int helper(int& dia, TreeNode* root){
        if(root == nullptr) return 0;
        int lh = helper(dia, root -> left);
        int rh = helper(dia, root -> right);
        dia = max(dia, lh + rh);
        return max(lh, rh) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        helper(dia, root);
        return dia;
    }
};