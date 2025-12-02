using int64 = long long;  
const int64 MOD = 1000000007LL;
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int,int> cnt; 
        cnt.reserve(points.size()*2);

        for(auto &p : points){
            int y = p[1];
            cnt[y]++;
        }

        
        vector<int64> a;
        a.reserve(cnt.size());
        for(auto &kv : cnt){
            int64 c = kv.second;
            if(c >= 2){
                int64 comb2 = (c * (c - 1) / 2) % MOD;
                a.push_back(comb2);
            }
        }

        if(a.size() < 2) return 0;

        int64 sum = 0, sumSq = 0;
        for(int64 v : a){
            sum = (sum + v) % MOD;
            sumSq = (sumSq + (v * v) % MOD) % MOD;
        }

     
        int64 total = ( ( (sum * sum) % MOD - sumSq ) % MOD + MOD ) % MOD;

        int64 inv2 = (MOD + 1) / 2; 
        int64 ans = (total * inv2) % MOD;
        return (int)ans;
    }
};