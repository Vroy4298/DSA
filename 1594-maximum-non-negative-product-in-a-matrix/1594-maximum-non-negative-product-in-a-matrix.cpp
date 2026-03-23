using ll = long long;
const int MOD = 1e9 + 7;

class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
      
        
        vector<vector<vector<ll>>> dp(rows, vector<vector<ll>>(cols, vector<ll>(2)));
   
        dp[0][0][0] = grid[0][0];  
        dp[0][0][1] = grid[0][0]; 
      
       
        for (int i = 1; i < rows; ++i) {
            dp[i][0][0] = dp[i - 1][0][0] * grid[i][0];
            dp[i][0][1] = dp[i - 1][0][1] * grid[i][0];
        }
      
       
        for (int j = 1; j < cols; ++j) {
            dp[0][j][0] = dp[0][j - 1][0] * grid[0][j];
            dp[0][j][1] = dp[0][j - 1][1] * grid[0][j];
        }
     
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                int currentValue = grid[i][j];
              
                if (currentValue >= 0) {
                    dp[i][j][0] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * currentValue;
                    dp[i][j][1] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * currentValue;
                } else {
                    dp[i][j][0] = max(dp[i - 1][j][1], dp[i][j - 1][1]) * currentValue;
                    dp[i][j][1] = min(dp[i - 1][j][0], dp[i][j - 1][0]) * currentValue;
                }
            }
        }
  
        ll maxProduct = dp[rows - 1][cols - 1][1];
   
        return maxProduct < 0 ? -1 : static_cast<int>(maxProduct % MOD);
    }
};
