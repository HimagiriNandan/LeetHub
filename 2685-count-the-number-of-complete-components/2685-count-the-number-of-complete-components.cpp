class Solution {
public:
    void dfs(int node, vector<vector<int>>& graph, vector<int>& vis, int& nodes, int& degreeSum) {
        vis[node] = 1;
        nodes++;
        degreeSum += graph[node].size();
        for(auto it : graph[node]) {
            if(vis[it] == 0) {
                dfs(it, graph, vis, nodes, degreeSum);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto it: edges) {
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> vis(n, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i] == 0) {
                int nodes = 0;
                int degreeSum = 0;
                dfs(i, graph, vis, nodes, degreeSum);
                if(degreeSum == nodes * (nodes - 1)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};