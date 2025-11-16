class Solution {
public:
    int numSub(string s) {
        const long long MOD = 1e9 + 7;
        long long count = 0; 
        long long result = 0;

        for (char c : s) {
            if (c == '1') {
                count++; 
            } else {
               
                result = (result + (count * (count + 1) / 2) % MOD) % MOD;
                count = 0;
            }
        }

       
        result = (result + (count * (count + 1) / 2) % MOD) % MOD;

        return result;
    }
};
