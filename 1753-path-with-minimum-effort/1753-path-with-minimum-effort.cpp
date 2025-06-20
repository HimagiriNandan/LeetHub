class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, 
        greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, 1};
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r == n - 1 && c == m - 1){
                return diff;
            }
            for(int i = 0; i < 4; i++){
                int nr = r + dx[i];
                int nc = c + dy[i];
                if(nr >= 0 && nc >= 0 && nr < n && nc < m){
                    int differ = max(diff, abs(heights[r][c] - heights[nr][nc]));
                    if(differ < dist[nr][nc]){
                        dist[nr][nc] = differ;
                        pq.push({differ, {nr, nc}});
                    }
                }
            }
        }
        return -1;
    }
};