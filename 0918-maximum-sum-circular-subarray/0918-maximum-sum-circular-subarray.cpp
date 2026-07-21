class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {

        // Step 1: Initialize variables
        int totalSum = nums[0];

        int currentMax = nums[0];
        int maxSum = nums[0];

        int currentMin = nums[0];
        int minSum = nums[0];

        // Step 2: Traverse the array
        for(int i = 1; i < nums.size(); i++)
        {
            // Calculate total array sum
            totalSum += nums[i];

            // Normal Kadane (Maximum Subarray)
            currentMax = max(nums[i], currentMax + nums[i]);
            maxSum = max(maxSum, currentMax);

            // Mirror Kadane (Minimum Subarray)
            currentMin = min(nums[i], currentMin + nums[i]);
            minSum = min(minSum, currentMin);
        }

        // Step 3: Special Case
        // If all elements are negative
        if(maxSum < 0)
            return maxSum;

        // Step 4: Circular Sum
        int circularSum = totalSum - minSum;

        // Step 5: Final Answer
        return max(maxSum, circularSum);
    }
};