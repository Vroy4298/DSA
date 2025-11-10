class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        vector<int> st; 

        for (int i = 0; i < n; ++i) {
            int v = nums[i];
            if (v == 0) {
             
                st.clear();
                continue;
            }
         
            while (!st.empty() && st.back() > v) st.pop_back();
            if (st.empty() || st.back() < v) {
                st.push_back(v);
                ++res;
            }
         
        }

        return static_cast<int>(res);
    }
};
