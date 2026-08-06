class Solution {
public:
    int smallestNumber(int n, int t) {
        
        for (int current = n; ; ++current) {
          
            int digitProduct = 1;
            int temp = current;
       
            while (temp > 0) {
                int digit = temp % 10;  // Get the last digit
                digitProduct *= digit;   // Multiply to the product
                temp /= 10;              // Remove the last digit
            }
          
            if (digitProduct % t == 0) {
                return current;  
            }
        }
    }
};