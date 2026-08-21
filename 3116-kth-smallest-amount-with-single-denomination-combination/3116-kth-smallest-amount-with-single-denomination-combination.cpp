class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        using ll = long long;
        int n = coins.size();

        auto countMultiples = [&](ll maxValue) -> ll {
            ll totalCount = 0;

            for (int mask = 1; mask < (1 << n); ++mask) {
                ll lcmValue = 1;

                for (int bitPos = 0; bitPos < n; ++bitPos) {
                    if ((mask >> bitPos) & 1) {
                        lcmValue = lcm(lcmValue, static_cast<ll>(coins[bitPos]));
                        if (lcmValue > maxValue) {
                            break;
                        }
                    }
                }

                int subsetSize = __builtin_popcount(mask);
                if (subsetSize & 1) {
                    totalCount += maxValue / lcmValue;
                } else {
                    totalCount -= maxValue / lcmValue;
                }
            }

            return totalCount;
        };

        
        auto feasible = [&](ll mid) -> bool {
            return countMultiples(mid) >= k;
        };

   
        ll left = 1;
        ll right = 1e11;
        ll firstTrueIndex = -1;

        while (left <= right) {
            ll mid = left + (right - left) / 2;
            if (feasible(mid)) {
                firstTrueIndex = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return firstTrueIndex;
    }
};
