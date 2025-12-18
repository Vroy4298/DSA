class Solution {
public:
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        int n = prices.size();
        long long orig = 0;
        for (int i = 0; i < n; i++)
            orig += 1LL * strategy[i] * prices[i];

        int half = k / 2;

        vector<long long> firstHalf(n), secondHalf(n);

        for (int i = 0; i < n; i++) {
            firstHalf[i]  = (0 - strategy[i]) * 1LL * prices[i];
            secondHalf[i] = (1 - strategy[i]) * 1LL * prices[i];
        }

        long long bestGain = 0;
        long long current = 0;

        // Initial window [0..k-1]
        for (int i = 0; i < half; i++) 
            current += firstHalf[i];
        
        for (int i = half; i < k; i++) 
            current += secondHalf[i];
        
        bestGain = max(bestGain, current);

        // Slide the window
        for (int l = 1; l + k - 1 < n; l++) {
            int r = l + k - 1;

            current -= firstHalf[l - 1];
            current -= secondHalf[l - 1 + half];

            current += firstHalf[l + half - 1];
            current += secondHalf[r];

            bestGain = max(bestGain, current);
        }

        return orig + bestGain;
    }
};
