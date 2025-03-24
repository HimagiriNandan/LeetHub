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
    int helper(int& maxi, TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int lh = max(0, helper(maxi, root -> left));
        int rh = max(0, helper(maxi, root -> right));
        maxi = max(lh + rh + root -> val, maxi);
        return max(lh, rh) + root -> val;
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        helper(maxi, root);
        return maxi;
    }
};