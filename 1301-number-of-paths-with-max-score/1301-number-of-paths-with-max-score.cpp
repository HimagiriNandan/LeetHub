class Solution {
public:
    const int MOD = 1000000007;
    const int NEG = -100000000;

    vector<vector<pair<int,int>>> dp;
    vector<vector<int>> vis;

    pair<int,int> solve(vector<string>& board, int i, int j) {

        if (i < 0 || j < 0)
            return {NEG, 0};

        if (board[i][j] == 'X')
            return {NEG, 0};

        if (i == 0 && j == 0)
            return {0, 1};

        if (vis[i][j])
            return dp[i][j];

        vis[i][j] = 1;

        auto up = solve(board, i - 1, j);
        auto left = solve(board, i, j - 1);
        auto diag = solve(board, i - 1, j - 1);

        int bestScore = max({up.first, left.first, diag.first});

        if (bestScore == NEG)
            return dp[i][j] = {NEG, 0};

        long long ways = 0;

        if (up.first == bestScore)
            ways += up.second;

        if (left.first == bestScore)
            ways += left.second;

        if (diag.first == bestScore)
            ways += diag.second;

        ways %= MOD;

        if (isdigit(board[i][j]))
            bestScore += board[i][j] - '0';

        return dp[i][j] = {bestScore, (int)ways};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {

        int n = board.size();

        dp.assign(n, vector<pair<int,int>>(n));
        vis.assign(n, vector<int>(n, 0));

        auto ans = solve(board, n - 1, n - 1);

        if (ans.second == 0)
            return {0, 0};

        return {ans.first, ans.second};
    }
};