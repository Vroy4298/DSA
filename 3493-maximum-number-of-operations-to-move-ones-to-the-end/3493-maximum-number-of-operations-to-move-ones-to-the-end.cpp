class Solution {
public:
    int maxOperations(string s) {
        long long ans = 0;
        long long cnt = 0;      

        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '1') {
                ++cnt;
            } else if (i > 0 && s[i - 1] == '1') {
                ans += cnt;
            }
        }
        return (int)ans;
    }
};
