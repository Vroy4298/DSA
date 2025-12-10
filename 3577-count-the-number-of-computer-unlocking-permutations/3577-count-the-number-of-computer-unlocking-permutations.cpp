class Solution {
public:
    static const int MOD = 1'000'000'007;

    long long modpow(long long a, long long b) {
        long long r = 1;
        while (b) {
            if (b & 1) r = (r * a) % MOD;
            a = (a * a) % MOD;
            b >>= 1;
        }
        return r;
    }

    int countPermutations(vector<int>& complexity) {
        int n = complexity.size();

        int minSoFar = complexity[0];

        for (int i = 1; i < n; i++) {
            if (complexity[i] <= minSoFar) {
                return 0;  // no valid parent
            }
            minSoFar = min(minSoFar, complexity[i]);
        }

        // All nodes 1..n-1 have at least 1 valid parent -> free to permute
        long long ans = 1;
        for (int i = 2; i <= n-1; i++)
            ans = (ans * i) % MOD;

        return ans;
    }
};
