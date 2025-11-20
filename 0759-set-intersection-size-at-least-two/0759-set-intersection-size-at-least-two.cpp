class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& in) {

        
        sort(in.begin(), in.end(), [](auto &a, auto &b){
            return a[1] < b[1] || (a[1] == b[1] && a[0] > b[0]);
        });

        int a = -1, b = -1; 
        int ans = 0;

        for (auto &v : in) {
            int L = v[0], R = v[1];

            bool hasA = (a >= L && a <= R);
            bool hasB = (b >= L && b <= R);

            if (hasA && hasB) continue;         

            if (hasB) {                      
                a = b;
                b = R;
                ans += 1;
            } else {                         
                a = R - 1;
                b = R;
                ans += 2;
            }
        }
        return ans;
    }
};
