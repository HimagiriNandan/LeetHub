class Node{
    public:

    Node* links[2];

    bool containsKey(int bit){
        return (links[bit] != nullptr);
    }

    void put(int bit, Node* node){
        links[bit] = node;
    }

    Node* get(int bit){
        return links[bit];
    }

};

class Trie{
    public:
    Node* root;
    Trie(){
        root = new Node();
    }

    void insert(int n){
        Node* node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (n >> i) & 1;
            if(!node->containsKey(bit)){
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMaxXor(int n){
        Node* node = root;
        int maxi = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (n >> i) & 1;
            if(node->containsKey(1 - bit)){
                maxi = maxi | (1 << i);
                node = node->get(1-bit);
            }else{
                node = node->get(bit);
            }
        }
        return maxi;
    }

};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie* trie = new Trie();
        int n = nums.size();
        for(int i = 0; i < n; i++){
            trie->insert(nums[i]);
        }
        int maxi = 0;
        for(int num : nums){
            maxi = max(maxi, trie->getMaxXor(num));
        }
        return maxi;
    }
};