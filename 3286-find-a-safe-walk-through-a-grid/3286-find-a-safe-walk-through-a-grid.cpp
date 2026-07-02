class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> best(m, vector<int>(n, -1));
        priority_queue<tuple<int, int, int>> pq;
        if(grid[0][0] == 1) health--;
        int dx[] = {-1, 0, +1, 0};
        int dy[] = {0, +1, 0, -1};
        pq.push({health, 0, 0});
        best[0][0] = health;
        while(!pq.empty()) {
            auto [h, r, c] = pq.top();
            pq.pop();
            if(r == m - 1 && c == n - 1 && h >= 1) {
                return true;
            }
            for(int i = 0; i < 4; i++) {
                int dr = r + dx[i];
                int dc = c + dy[i];
                if(dr >= 0 && dc >= 0 && dr < m && dc < n) {
                    int newHealth = h - grid[dr][dc];
                    if(newHealth > 0 && newHealth > best[dr][dc]) {
                        best[dr][dc] = newHealth;
                        pq.push({newHealth, dr, dc});
                    }
                }
            }
        }
        return false;
    }
};