class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> result;
      
        for (int num : nums) {
            if (num == 2) {
                result.push_back(-1);
            } else {
                for (int bitPosition = 1; bitPosition < 32; ++bitPosition) {
       
                    if (((num >> bitPosition) & 1) ^ 1) {
                        int answer = num ^ (1 << (bitPosition - 1));
                        result.push_back(answer);
                        break;
                    }
                }
            }
        }
      
        return result;
    }
};