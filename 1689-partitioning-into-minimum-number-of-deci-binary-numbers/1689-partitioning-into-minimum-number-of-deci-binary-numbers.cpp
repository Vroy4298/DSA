class Solution {
public:
    int minPartitions(string n) {
        // Initialize the maximum digit found so far
        int maxDigit = 0;
      
        // Iterate through each character in the string
        for (char& digit : n) {
            // Convert character to integer and update maximum
            maxDigit = max(maxDigit, digit - '0');
        }
        return maxDigit;
    }
};