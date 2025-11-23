class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> dp(3, -1); 
        dp[0] = 0;          

        for (int x : nums) {
            vector<int> cur = dp;
            for (int r = 0; r < 3; r++) {
                if (cur[r] < 0) continue;            
                dp[(r + x) % 3] = max(dp[(r + x) % 3], cur[r] + x);
            }
        }
        return dp[0];
    }
};
