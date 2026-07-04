class Solution {
public:

    void dfs(int node, vector<vector<pair<int, int>>>& graph, vector<int>& vis, int& ans) {
        vis[node] = 1;
        for(auto it: graph[node]) {
            ans = min(ans, it.second);
            if(!vis[it.first]){
                dfs(it.first, graph, vis, ans);
            }
        }
    }

    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> graph(n + 1);
        for(auto it : roads) {
            int u = it[0];
            int v = it[1];
            int dist = it[2];
            graph[u].push_back({v, dist});
            graph[v].push_back({u, dist});
        }
        vector<int> vis(n + 1, 0);
        int ans = INT_MAX;
        dfs(1, graph, vis, ans);
        return ans;
    }
};