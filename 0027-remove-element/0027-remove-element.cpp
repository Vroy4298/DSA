#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0; // Slow pointer
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j]; // Move non-val elements to the front
                i++;
            }
        }
        return i; // Number of elements not equal to val
    }
};
