class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        long long sum =0;
         for (long long b : batteries) sum += b;
        long long low = 0, high = sum /n;
        while (low < high) {
            long long mid = (low + high + 1) / 2; 
            long long total = 0;
            for (long long b : batteries) {
                total += min(b, mid);
                if (total >= mid * n) break; 
            }

            if (total >= mid * n)
                low = mid;      
            else
                high = mid - 1; 
        }

        return low;
    }
};
    
