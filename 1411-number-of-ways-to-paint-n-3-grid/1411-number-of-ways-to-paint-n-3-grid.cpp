using ll = long long;

class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        ll patternABA = 6;  
        ll patternABC = 6; 
      
        while (--n) {
            
            ll nextPatternABA = (patternABA * 3 + patternABC * 2) % MOD;
            ll nextPatternABC = (patternABA * 2 + patternABC * 2) % MOD;
          
            patternABA = nextPatternABA;
            patternABC = nextPatternABC;
        }
      
        return static_cast<int>((patternABA + patternABC) % MOD);
    }
};