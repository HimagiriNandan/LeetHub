class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> q;
        int fresh = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) {
                    q.push({0, {i, j}});
                } else if(grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        int ans = 0;
        int dx[] = {-1, 0, +1, 0};
        int dy[] = {0, +1, 0, -1};
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            int t = it.first;
            ans = max(ans, t);
            int row = it.second.first;
            int col = it.second.second;
            for(int i = 0; i < 4; i++) {
                int srow = row + dx[i];
                int scol = col + dy[i];
                if(srow < grid.size() && srow >= 0 && scol < grid[0].size() && scol >= 0 && grid[srow][scol] == 1) {
                    grid[srow][scol] = 2;
                    fresh--;
                    q.push({t + 1, {srow, scol}});
                }
            }
        }
        return fresh == 0 ? ans : -1;
    }
};