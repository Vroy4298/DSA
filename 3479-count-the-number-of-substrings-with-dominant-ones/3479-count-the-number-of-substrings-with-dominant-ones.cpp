class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> pref(n+1, 0);
        vector<int> zpos;

        for (int i = 0; i < n; i++) {
            pref[i+1] = pref[i] + (s[i] == '1');
            if (s[i] == '0') zpos.push_back(i);
        }

        long long ans = 0;

        // Count all-ones substrings
        int last = -1;
        for (int z : zpos) {
            long long len = z - last - 1;
            ans += len * (len + 1) / 2;
            last = z;
        }
        long long len = n - last - 1;
        ans += len * (len + 1) / 2;

        int Z = zpos.size();
        int K = sqrt(n) + 3;
        for (int i = 0; i < Z; i++) {
            for (int k = 1; k <= K && i + k - 1 < Z; k++) {
                int L = zpos[i];
                int R = zpos[i + k - 1];

                long long needed = 1LL * k * k;
                long long internal = pref[R] - pref[L + 1];

   
                long long leftMax = (i == 0 ? zpos[0] : zpos[i] - zpos[i - 1] - 1);
           
                long long rightMax = ((i + k - 1 == Z - 1)
                                       ? n - 1 - zpos[Z - 1]
                                       : zpos[i + k] - zpos[i + k - 1] - 1);

                long long base = internal;

                long long needLeftRight = needed - base;
                if (needLeftRight <= 0) {
                    ans += (leftMax + 1) * (rightMax + 1);
                    continue;
                }

                for (long long left = 0; left <= leftMax; left++) {
                    long long needRight = needLeftRight - left;
                    if (needRight <= 0) {
                        ans += (rightMax + 1);
                    } else if (needRight <= rightMax) {
                        ans += (rightMax - needRight + 1);
                    }
                }
            }
        }

        return ans;
    }
};
