class Node {
public:
    Node* links[2];

    Node() {
        links[0] = nullptr;
        links[1] = nullptr;
    }

    bool containsKey(int bit) {
        return (links[bit] != nullptr);
    }

    void put(int bit, Node* node) {
        links[bit] = node;
    }

    Node* get(int bit) {
        return links[bit];
    }
};

class Trie {
public:
    Node* root = nullptr;
    Trie() {
        this->root = new Node();
    }

    void insert(int num) {
        Node* node = root;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containsKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
        }
    }

    int getMaxXor(int num) {
        Node* node = root;
        int maxXor = 0;
        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (node->containsKey(1 - bit)) {
                maxXor |= (1 << i);
                node = node->get(1 - bit);
            } else {
                node = node->get(bit);
            }
        }
        return maxXor;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<pair<int, pair<int, int>>> que;
        for (int i = 0; i < queries.size(); i++) {
            que.push_back({queries[i][1], {queries[i][0], i}});
        }
        sort(que.begin(), que.end());
        vector<int> ans(queries.size());
        int ind = 0;
        Trie trie;
        for (int i = 0; i < que.size(); i++) {
            int ai = que[i].first;
            int xi = que[i].second.first;
            int qInd = que[i].second.second;
            while (ind < nums.size() && nums[ind] <= ai) {
                trie.insert(nums[ind]);
                ind++;
            }
            if (ind == 0) ans[qInd] = -1;
            else ans[qInd] = trie.getMaxXor(xi);
        }
        return ans;
    }
};
