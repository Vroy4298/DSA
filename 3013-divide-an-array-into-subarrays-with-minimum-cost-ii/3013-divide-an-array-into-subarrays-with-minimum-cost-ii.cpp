class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        // Adjust k to represent how many elements we need to select (excluding nums[0])
        --k;
      
        // Two multisets to maintain the k smallest elements (leftSet) and remaining elements (rightSet)
        // Initialize leftSet with elements from index 1 to dist+1 (the first window)
        multiset<int> leftSet(nums.begin() + 1, nums.begin() + dist + 2);
        multiset<int> rightSet;
      
        // Calculate initial sum of all elements in the first window
        long long currentSum = accumulate(nums.begin(), nums.begin() + dist + 2, 0LL);
      
        // Adjust leftSet to contain exactly k smallest elements
        // Move larger elements to rightSet
        while (leftSet.size() > k) {
            int largestInLeft = *leftSet.rbegin();
            leftSet.erase(leftSet.find(largestInLeft));
            currentSum -= largestInLeft;
            rightSet.insert(largestInLeft);
        }
      
        // Initialize answer with the current sum
        long long answer = currentSum;
      
        // Slide the window through the array
        for (int i = dist + 2; i < nums.size(); ++i) {
            // Remove the element that goes out of the window
            int elementToRemove = nums[i - dist - 1];
            auto iter = leftSet.find(elementToRemove);
          
            if (iter != leftSet.end()) {
                // Element is in leftSet, remove it and update sum
                leftSet.erase(iter);
                currentSum -= elementToRemove;
            } else {
                // Element is in rightSet, just remove it
                rightSet.erase(rightSet.find(elementToRemove));
            }
          
            // Add the new element entering the window
            int newElement = nums[i];
          
            // Decide whether to add to leftSet or rightSet based on comparison with largest in leftSet
            if (newElement < *leftSet.rbegin()) {
                leftSet.insert(newElement);
                currentSum += newElement;
            } else {
                rightSet.insert(newElement);
            }
          
            // Rebalance: if leftSet has too few elements, move smallest from rightSet
            while (leftSet.size() == k - 1) {
                int smallestInRight = *rightSet.begin();
                rightSet.erase(rightSet.find(smallestInRight));
                leftSet.insert(smallestInRight);
                currentSum += smallestInRight;
            }
          
            // Rebalance: if leftSet has too many elements, move largest to rightSet
            while (leftSet.size() == k + 1) {
                int largestInLeft = *leftSet.rbegin();
                leftSet.erase(leftSet.find(largestInLeft));
                currentSum -= largestInLeft;
                rightSet.insert(largestInLeft);
            }
          
            // Update the minimum answer
            answer = min(answer, currentSum);
        }
      
        return answer;
    }
};