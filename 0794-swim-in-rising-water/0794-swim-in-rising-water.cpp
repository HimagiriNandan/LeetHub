class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        pq.push({grid[0][0], {0, 0}});
        vis[0][0] = 1;
        int res = 0;
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int t = it.first;
            int r = it.second.first;
            int c = it.second.second;
            res = max(res, t);
            if(r == grid.size() - 1 && c == grid[0].size() - 1){
                return res;
            }
            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nc >= 0 && nr >= 0 && nc < grid[0].size() && nr < grid.size() &&
                !vis[nr][nc]){
                    vis[nr][nc] = 1;
                    pq.push({grid[nr][nc], {nr, nc}});
                }
            }
        }
        return -1;
    }
};