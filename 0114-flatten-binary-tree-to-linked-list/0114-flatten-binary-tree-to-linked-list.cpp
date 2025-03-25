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
    void preorder(TreeNode* &prev, TreeNode* root){
        if(root == nullptr){
            return;
        }
        if(root != prev){
            prev -> right = root;
            prev -> left = nullptr;
            prev = root;
        }
        TreeNode* left = root -> left;
        TreeNode* right = root -> right;
        preorder(prev, left);
        preorder(prev, right);
    }
    void flatten(TreeNode* root) {
        preorder(root, root);
    }
};