class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        vector<vector<int>> safeScore(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    safeScore[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n &&
                    safeScore[nr][nc] == INT_MAX) {

                    safeScore[nr][nc] = safeScore[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        priority_queue<tuple<int, int, int>> pq;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        pq.push({safeScore[0][0], 0, 0});

        while (!pq.empty()) {
            auto [currSafe, r, c] = pq.top();
            pq.pop();

            if (vis[r][c])
                continue;

            vis[r][c] = true;

            if (r == n - 1 && c == n - 1)
                return currSafe;

            for (int k = 0; k < 4; k++) {
                int nr = r + dx[k];
                int nc = c + dy[k];

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !vis[nr][nc]) {

                    int newSafe = min(currSafe, safeScore[nr][nc]);
                    pq.push({newSafe, nr, nc});
                }
            }
        }

        return 0;
    }
};