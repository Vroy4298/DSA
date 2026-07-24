class Solution {
public:
    int thirdMax(vector<int>& nums) {

        long long largest = LLONG_MIN;
        long long secondLargest = LLONG_MIN;
        long long thirdMax = LLONG_MIN;

        for (int i = 0; i < nums.size(); i++) {

            // Ignore duplicates
            if (nums[i] == largest || nums[i] == secondLargest || nums[i] == thirdMax)
                continue;

            if (nums[i] > largest) {
                thirdMax = secondLargest;
                secondLargest = largest;
                largest = nums[i];
            }
            else if (nums[i] > secondLargest) {
                thirdMax = secondLargest;
                secondLargest = nums[i];
            }
            else if (nums[i] > thirdMax) {
                thirdMax = nums[i];
            }
        }

        if (thirdMax == LLONG_MIN)
            return largest;

        return thirdMax;
    }
};