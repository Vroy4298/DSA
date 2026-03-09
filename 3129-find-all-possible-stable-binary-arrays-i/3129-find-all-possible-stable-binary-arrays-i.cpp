class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        const int MOD = 1e9 + 7;
        using ll = long long;
        vector<vector<array<ll, 2>>> dp(zero + 1, vector<array<ll, 2>>(one + 1, {-1, -1}));
        auto countStableArrays = [&](this auto&& countStableArrays, int zerosLeft, int onesLeft, int lastType) -> ll {
            if (zerosLeft < 0 || onesLeft < 0) {
                return 0;
            }
            if (zerosLeft == 0) {
             
                return lastType == 1 && onesLeft <= limit;
            }
          
           
            if (onesLeft == 0) {
               
                return lastType == 0 && zerosLeft <= limit;
            }
          

            ll& result = dp[zerosLeft][onesLeft][lastType];
            if (result != -1) {
                return result;
            }
  
            if (lastType == 0) {
   
                result = (countStableArrays(zerosLeft - 1, onesLeft, 0) + 
                         countStableArrays(zerosLeft - 1, onesLeft, 1) - 
                         countStableArrays(zerosLeft - limit - 1, onesLeft, 1) + MOD) % MOD;
            } else {
               
                result = (countStableArrays(zerosLeft, onesLeft - 1, 0) + 
                         countStableArrays(zerosLeft, onesLeft - 1, 1) - 
                         countStableArrays(zerosLeft, onesLeft - limit - 1, 0) + MOD) % MOD;
            }
          
            return result;
        };
      

        return (countStableArrays(zero, one, 0) + countStableArrays(zero, one, 1)) % MOD;
    }
};