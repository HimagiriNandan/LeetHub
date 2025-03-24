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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        bool flag = false;
        vector<vector<int>> result;
        if(!root) return result;
        while(!q.empty()){
            int size = q.size();
            vector<int> res;
            for(int i = 0; i < size; i++){
                TreeNode* current = q.front();
                q.pop();
                res.push_back(current -> val);
                if(current -> left != nullptr){
                    q.push(current -> left);
                }if(current -> right != nullptr){
                    q.push(current -> right);
                }
            }
            if(flag){
                reverse(res.begin(), res.end());
                result.push_back(res);
            }else{
                result.push_back(res);
            }
            flag = !flag;
        }
        return result;
    }
};