class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {

        unordered_map<int, vector<int>> rows, cols;

        for (auto &b : buildings) {
            rows[b[0]].push_back(b[1]);
            cols[b[1]].push_back(b[0]);
        }

        // Sort for binary search
        for (auto &p : rows) sort(p.second.begin(), p.second.end());
        for (auto &p : cols) sort(p.second.begin(), p.second.end());

        int count = 0;

        for (auto &b : buildings) {
            int x = b[0], y = b[1];

            auto &r = rows[x];
            auto &c = cols[y];

          
            bool left = binary_search(r.begin(), r.end(), y-1) ||
            lower_bound(r.begin(), r.end(), y) != r.begin();
            bool right = upper_bound(r.begin(), r.end(), y) != r.end();
            bool above = lower_bound(c.begin(), c.end(), x) != c.begin();
            bool below = upper_bound(c.begin(), c.end(), x) != c.end();

            if (left && right && above && below)
                count++;
        }

        return count;
    }
};
