class Solution {
public:
    int rotatedDigits(int n) {
        int digitMapping[10] = {0, 1, 5, -1, -1, 2, 9, -1, 8, 6};
      
        auto isGoodNumber = [&](int number) -> bool {
            int rotatedNumber = 0; 
            int originalNumber = number; 
            int placeValue = 1;  
     
            while (originalNumber > 0) {
                int currentDigit = originalNumber % 10;
              
                
                if (digitMapping[currentDigit] == -1) {
                    return false;
                }
             
                rotatedNumber = digitMapping[currentDigit] * placeValue + rotatedNumber;
                placeValue *= 10;
                originalNumber /= 10;
            }
          
            return number != rotatedNumber;
        };
 
        int goodNumberCount = 0;
        for (int i = 1; i <= n; ++i) {
            if (isGoodNumber(i)) {
                goodNumberCount++;
            }
        }
      
        return goodNumberCount;
    }
};