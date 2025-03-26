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
    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int &index, int left, int right, unordered_map<int, int>& mp){
        if(left > right){
            return nullptr;
        }
        int currentEle = preorder[index++];
        TreeNode* node = new TreeNode(currentEle);
        int inorderInd = mp[currentEle];
        node -> left = helper(preorder, inorder, index, left, inorderInd - 1, mp);
        node -> right = helper(preorder, inorder, index, inorderInd + 1, right, mp);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int index = 0;
        return helper(preorder, inorder, index, 0, inorder.size() - 1, mp);
    }
};