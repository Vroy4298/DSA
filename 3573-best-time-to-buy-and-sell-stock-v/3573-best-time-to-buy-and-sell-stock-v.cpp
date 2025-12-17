class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        const long long NEG = -4e18;
        int n = prices.size();

        vector<vector<long long>> dp(k + 1, vector<long long>(3, NEG));
        dp[0][0] = 0;  // flat, 0 transactions

        for (int price : prices) {
            auto next = dp;

            for (int t = 0; t <= k; t++) {
                // From flat
                if (dp[t][0] != NEG) {
                    next[t][1] = max(next[t][1], dp[t][0] - price); // buy
                    next[t][2] = max(next[t][2], dp[t][0] + price); // short
                }

                // From long → sell
                if (t < k && dp[t][1] != NEG) {
                    next[t + 1][0] = max(next[t + 1][0], dp[t][1] + price);
                }

     
                if (t < k && dp[t][2] != NEG) {
                    next[t + 1][0] = max(next[t + 1][0], dp[t][2] - price);
                }
            }

            dp = next;
        }

        long long ans = 0;
        for (int t = 0; t <= k; t++) {
            ans = max(ans, dp[t][0]); // must end flat
        }
        return ans;
    }
};
