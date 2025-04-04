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
    int findDepth(TreeNode* root){
        if(root == nullptr){
            return 0;
        }
        int l = 1 + findDepth(root -> left);
        int r = 1 + findDepth(root -> right);
        return max(l, r);
    }
    TreeNode* helper(TreeNode* root, int depth, int dep){
        if(root == nullptr){
            return nullptr;
        }
        if(dep == depth){
            return root;
        }
        TreeNode* left = helper(root -> left, depth, dep + 1);
        TreeNode* right = helper(root -> right, depth, dep + 1);

        if(left && right) return root;
        return (left) ? left : right;
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(!root) return root;
        int dep = findDepth(root);
        TreeNode* ans = helper(root, dep , 1);
        return ans;
    }
};