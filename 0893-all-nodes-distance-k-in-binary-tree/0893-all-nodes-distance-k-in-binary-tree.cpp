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
    void mark_parents(unordered_map<TreeNode*, TreeNode*> &parents, TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current -> left != nullptr){
                parents[current -> left] = current;
                q.push(current -> left);
            }
            if(current -> right != nullptr){
                parents[current -> right] = current;
                q.push(current -> right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root){
            return {};
        }
        unordered_map<TreeNode*, TreeNode*> parents;
        mark_parents(parents, root);
        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target] = true;
        int dist = 0;
        while(!q.empty()){
            int size = q.size();
            if(dist == k) break;
            dist++;
            for(int i = 0; i < size; i++){
                TreeNode* curr = q.front(); q.pop();
                if(curr -> left && !visited[curr -> left]){
                    q.push(curr -> left);
                    visited[curr -> left] = true;
                }
                if(curr -> right && !visited[curr -> right]){
                    q.push(curr -> right);
                    visited[curr -> right] = true;
                }
                if(parents[curr] && !visited[parents[curr]]){
                    q.push(parents[curr]);
                    visited[parents[curr]] = true;
                }
            }
        }
        vector<int> result;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            result.push_back(node -> val);
        }
        return result;
    }
};