/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* find(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr){
            return root;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* l = find(root -> left, p, q);
        TreeNode* r = find(root -> right, p, q);
        
        if(l!=nullptr && r!=nullptr){
            return root;
        }
        if(l!=nullptr){
            return l;
        }
        return r;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return find(root, p, q);
    }
};