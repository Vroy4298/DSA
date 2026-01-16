class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        // Lambda function to calculate all possible distances between fence positions
        auto calculateDistances = [](vector<int>& fences, int boundary) -> unordered_set<int> {
            // Add the boundary positions (1 and boundary) to the fence list
            fences.push_back(boundary);
            fences.push_back(1);
          
            // Sort all fence positions for systematic distance calculation
            sort(fences.begin(), fences.end());
          
            // Store all possible distances in a set
            unordered_set<int> distances;
          
            // Calculate distance between every pair of fence positions
            for (int i = 0; i < fences.size(); ++i) {
                for (int j = 0; j < i; ++j) {
                    distances.insert(fences[i] - fences[j]);
                }
            }
          
            return distances;
        };
      
        // Calculate all possible horizontal distances
        unordered_set<int> horizontalDistances = calculateDistances(hFences, m);
      
        // Calculate all possible vertical distances
        unordered_set<int> verticalDistances = calculateDistances(vFences, n);
      
        // Find the maximum distance that exists in both horizontal and vertical sets
        int maxSideLength = 0;
        for (int distance : horizontalDistances) {
            // Check if this distance can form a square (exists in both dimensions)
            if (verticalDistances.count(distance)) {
                maxSideLength = max(maxSideLength, distance);
            }
        }
      
        // Define modulo for the result
        const int MOD = 1e9 + 7;
      
        // Return the area of the largest square, or -1 if no square is possible
        return maxSideLength > 0 ? (1LL * maxSideLength * maxSideLength) % MOD : -1;
    }
};
