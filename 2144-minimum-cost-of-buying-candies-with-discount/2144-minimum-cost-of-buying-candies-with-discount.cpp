class Solution {
public:
    int minimumCost(vector<int>& cost) {
        // Sort the array in descending order to prioritize buying expensive items first
        sort(cost.rbegin(), cost.rend());
      
        int totalCost = 0;
      
        // Process items in groups of 3
        // Buy 2 items and get the 3rd one free (skip every 3rd item)
        for (int i = 0; i < cost.size(); i += 3) {
            // Add the first item in the group
            totalCost += cost[i];
          
            // Add the second item if it exists
            if (i + 1 < cost.size()) {
                totalCost += cost[i + 1];
            }
            // The third item (i + 2) is free, so we skip it
        }
      
        return totalCost;
    }
};
