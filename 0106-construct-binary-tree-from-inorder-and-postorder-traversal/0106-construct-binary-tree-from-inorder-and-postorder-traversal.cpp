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
    TreeNode* helper(vector<int>& inorder, vector<int>& postorder, unordered_map<int, int>& mp, int left, int right, int &index){
        if(left > right){
            return nullptr;
        }
        int currentEle = postorder[index--];
        TreeNode* node = new TreeNode(currentEle);

        int inorderIndex = mp[currentEle];
        node -> right = helper(inorder, postorder, mp, inorderIndex + 1, right, index);
        node -> left = helper(inorder, postorder, mp, left, inorderIndex - 1, index);

        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for(int i = 0; i < inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        int index = postorder.size() - 1;
        return helper(inorder, postorder, mp, 0, inorder.size() - 1, index);
    }
};