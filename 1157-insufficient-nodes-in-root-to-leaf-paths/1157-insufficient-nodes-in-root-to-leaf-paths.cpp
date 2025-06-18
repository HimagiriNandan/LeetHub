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
    TreeNode* helper(TreeNode* root, int limit, int sum){
        if(root == nullptr) return root;
        sum += root -> val;
        if(root -> left == nullptr && root -> right == nullptr){
            if(sum < limit) return nullptr;
            else return root;
        }
        root -> left = helper(root -> left, limit, sum);
        root -> right = helper(root -> right, limit, sum);
        if(root -> left == nullptr && root -> right == nullptr) return nullptr;
        return root;
    }
    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        return helper(root, limit, 0);
    }
};