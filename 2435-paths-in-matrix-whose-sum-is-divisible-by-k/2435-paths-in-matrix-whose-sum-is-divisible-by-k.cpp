class Solution {
public:
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        const int MOD = 1000000007;
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(k, 0));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                vector<int> cur(k, 0);
                int add = grid[i][j] % k;

                if (i == 0 && j == 0) {
                    cur[add] = 1;
                } else {
                    if (i > 0) {
                        for (int r = 0; r < k; r++) {
                            if (dp[j][r] == 0) continue;
                            int nr = (r + add) % k;
                            cur[nr] = (cur[nr] + dp[j][r]) % MOD;
                        }
                    }
                    if (j > 0) {
                        for (int r = 0; r < k; r++) {
                            if (dp[j - 1][r] == 0) continue;
                            int nr = (r + add) % k;
                            cur[nr] = (cur[nr] + dp[j - 1][r]) % MOD;
                        }
                    }
                }

                dp[j] = cur;
            }
        }

        return dp[n - 1][0];
    }
};
