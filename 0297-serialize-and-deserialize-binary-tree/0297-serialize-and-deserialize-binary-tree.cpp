/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root){
            return "";
        }
        string res = "";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == nullptr){
                res += "#,";
            }
            else{
                res += (to_string(node -> val) + ",");
                q.push(node -> left);
                q.push(node -> right);
            }
        }
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ""){
            return nullptr;
        }
        stringstream s(data);
        string str = "";
        getline(s, str, ',');
        TreeNode* node = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            getline(s, str, ',');
            if(str != "#"){
                TreeNode* leftNode = new TreeNode(stoi(str));
                curr -> left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str != "#"){
                TreeNode* rightNode = new TreeNode(stoi(str));
                curr -> right = rightNode;
                q.push(rightNode);
            }
        }
        return node;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));