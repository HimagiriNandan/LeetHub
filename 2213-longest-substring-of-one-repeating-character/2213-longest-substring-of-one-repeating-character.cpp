struct Node {
    char leftChar;
    char rightChar;

    int prefix;
    int suffix;
    int best;
    int len;
};

class Solution {
public:
    string st;
    vector<Node> tree;

    // Merge two adjacent segments
    Node merge(Node left, Node right) {

        Node parent;

        // Length of combined segment
        parent.len = left.len + right.len;

        // First and last characters
        parent.leftChar = left.leftChar;
        parent.rightChar = right.rightChar;

        // ---------------- Prefix ----------------

        parent.prefix = left.prefix;

        // If the entire left segment has the same character
        // and the boundary characters match,
        // prefix can extend into the right segment.
        if (left.prefix == left.len &&
            left.rightChar == right.leftChar) {

            parent.prefix = left.prefix + right.prefix;
        }

        // ---------------- Suffix ----------------

        parent.suffix = right.suffix;

        // If the entire right segment has the same character
        // and the boundary characters match,
        // suffix can extend into the left segment.
        if (right.suffix == right.len &&
            left.rightChar == right.leftChar) {

            parent.suffix = right.suffix + left.suffix;
        }

        // ---------------- Best ----------------

        // Best substring completely inside left or right
        parent.best = max(left.best, right.best);

        // Best substring crossing the boundary
        if (left.rightChar == right.leftChar) {

            parent.best = max(
                parent.best,
                left.suffix + right.prefix
            );
        }

        return parent;
    }

    // Build segment tree
    void build(int node, int low, int high) {

        // Leaf node
        if (low == high) {

            tree[node].leftChar = st[low];
            tree[node].rightChar = st[low];

            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            tree[node].len = 1;

            return;
        }

        int mid = low + (high - low) / 2;

        // Build left child
        build(2 * node, low, mid);

        // Build right child
        build(2 * node + 1, mid + 1, high);

        // Merge children
        tree[node] = merge(
            tree[2 * node],
            tree[2 * node + 1]
        );
    }

    // Point update
    void update(int node, int low, int high, int index, char ch) {

        // Reached the required index
        if (low == high) {

            tree[node].leftChar = ch;
            tree[node].rightChar = ch;

            tree[node].prefix = 1;
            tree[node].suffix = 1;
            tree[node].best = 1;
            tree[node].len = 1;

            return;
        }

        int mid = low + (high - low) / 2;

        // Go to the child containing index
        if (index <= mid) {

            update(
                2 * node,
                low,
                mid,
                index,
                ch
            );

        } else {

            update(
                2 * node + 1,
                mid + 1,
                high,
                index,
                ch
            );
        }

        // Recalculate current node
        tree[node] = merge(
            tree[2 * node],
            tree[2 * node + 1]
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        int n = s.length();

        st = s;

        tree.resize(4 * n);

        vector<int> ans;

        // Build initially
        build(1, 0, n - 1);

        // Process every query
        for (int i = 0; i < queryIndices.size(); i++) {

            update(
                1,
                0,
                n - 1,
                queryIndices[i],
                queryCharacters[i]
            );

            // Root represents the entire string
            ans.push_back(tree[1].best);
        }

        return ans;
    }
};