class Solution {
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
     
        vector<vector<int>> dp(n, vector<int>(n));

        auto calculateScoreDifference = [&](this auto&& calculateScoreDifference, int left, int right) -> int {
           
            if (left > right) {
                return 0;
            }
          

            if (dp[left][right] != 0) {
                return dp[left][right];
            }
            int takeLeft = nums[left] - calculateScoreDifference(left + 1, right);

            int takeRight = nums[right] - calculateScoreDifference(left, right - 1);

            return dp[left][right] = max(takeLeft, takeRight);
        };
      

        return calculateScoreDifference(0, n - 1) >= 0;
    }
};