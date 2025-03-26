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
    TreeNode* helper(vector<int>& preorder, int upperBound, int &index){
        if(index == preorder.size() || preorder[index] > upperBound) return nullptr;
        TreeNode* curr = new TreeNode(preorder[index++]);
        curr -> left = helper(preorder, curr -> val, index);
        curr -> right = helper(preorder, upperBound, index);
        return curr;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return nullptr;
        int i = 0;
        return helper(preorder, INT_MAX, i);
    }
};