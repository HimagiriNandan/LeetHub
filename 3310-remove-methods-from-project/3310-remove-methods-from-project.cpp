class Solution {
public:

    void dfs(int k, vector<vector<int>> &graph, vector<int> &vis) {
        vis[k] = 1;
        for(auto nei : graph[k]) {
            if(!vis[nei]) {
                dfs(nei, graph, vis);
            }
        }
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> graph(n);
        for(auto it : invocations) {
            int u = it[0];
            int v = it[1];
            graph[u].push_back(v);
        }
        vector<int> vis(n, 0);
        dfs(k, graph, vis);
        for(auto it : invocations) {
            int u = it[0];
            int v = it[1];
            if(!vis[u] && vis[v]) {
                vector<int> ans;
                for(int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!vis[i])
                ans.push_back(i);
        }
        return ans;
    }
};