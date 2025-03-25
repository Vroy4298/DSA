class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end()); 
        
        int occupied = 0, lastEnd = 0;
        for (auto &m : meetings) {
            int start = m[0], end = m[1];

            if (start > lastEnd) {
                occupied += (end - start + 1);
            } else if (end > lastEnd) {
                occupied += (end - lastEnd);
            }
          
            lastEnd = max(lastEnd, end);
        }
        return days -  occupied; 
    }
};
