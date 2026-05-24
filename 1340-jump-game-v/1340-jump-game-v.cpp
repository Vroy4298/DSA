class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
      
        // dp[i] stores the maximum number of indices that can be visited starting from index i
        vector<int> dp(n, 0);
      
        // DFS with memoization to calculate maximum jumps from index i
        function<int(int)> dfs = [&](int index) -> int {
            // Return cached result if already computed
            if (dp[index] != 0) {
                return dp[index];
            }
          
            // At minimum, we can visit the current index itself
            int maxVisits = 1;
          
            // Try jumping to the left (indices smaller than current)
            for (int j = index - 1; j >= 0; --j) {
                // Stop if distance exceeds d or we encounter a taller/equal building
                if (index - j > d || arr[j] >= arr[index]) {
                    break;
                }
                // Update maximum visits if jumping to j gives better result
                maxVisits = max(maxVisits, 1 + dfs(j));
            }
          
            // Try jumping to the right (indices larger than current)
            for (int j = index + 1; j < n; ++j) {
                // Stop if distance exceeds d or we encounter a taller/equal building
                if (j - index > d || arr[j] >= arr[index]) {
                    break;
                }
                // Update maximum visits if jumping to j gives better result
                maxVisits = max(maxVisits, 1 + dfs(j));
            }
          
            // Cache and return the result
            dp[index] = maxVisits;
            return maxVisits;
        };
      
        // Try starting from each index and find the maximum
        int result = 1;
        for (int i = 0; i < n; ++i) {
            result = max(result, dfs(i));
        }
      
        return result;
    }
};