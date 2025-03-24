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
    vector<int> postorderTraversal(TreeNode* root) {
        if(!root) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* current = st.top();
            st.pop();
            ans.push_back(current -> val);
            if(current -> left != nullptr) st.push(current->left);
            if(current -> right != nullptr) st.push(current -> right);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};