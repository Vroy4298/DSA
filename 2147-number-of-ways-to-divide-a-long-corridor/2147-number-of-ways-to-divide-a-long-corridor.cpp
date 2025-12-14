class Solution {
public:
    int numberOfWays(string corridor) {
        const int MOD = 1e9 + 7;
        
        int totalSeats = 0;
        for (char c : corridor)
            if (c == 'S') totalSeats++;
            
        if (totalSeats == 0 || totalSeats % 2 != 0)
            return 0;
        
        long long ways = 1;
        int seatCount = 0;
        int plantCount = 0;
        bool countingPlants = false;
        
        for (char c : corridor) {
            if (c == 'S') {
                seatCount++;
                
          
                if (seatCount == 2) {
                    countingPlants = true;
                    seatCount = 0;
                }
               
                else if (seatCount == 1 && countingPlants) {
                    ways = (ways * (plantCount + 1)) % MOD;
                    plantCount = 0;
                    countingPlants = false;
                }
            } else if (countingPlants) {
                plantCount++;
            }
        }
        
        return ways;
    }
};
