class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        // Count stones by their remainder when divided by 3
        // count[0]: stones with remainder 0
        // count[1]: stones with remainder 1  
        // count[2]: stones with remainder 2
        vector<int> count(3, 0);
        for (int stone : stones) {
            count[stone % 3]++;
        }
      
        // Create a swapped version where remainder 1 and 2 counts are swapped
        // This simulates Alice starting with a stone of remainder 2 instead of 1
        vector<int> countSwapped = {count[0], count[2], count[1]};
      
        // Lambda function to check if Alice can win with a given stone configuration
        // The strategy assumes Alice starts by picking a stone with remainder 1
        auto checkAliceWins = [](vector<int> stoneCount) -> bool {
            // Alice must start with a stone of remainder 1
            stoneCount[1]--;
            if (stoneCount[1] < 0) {
                return false;  // No stone with remainder 1 to start with
            }
          
            // Calculate total moves in optimal play
            // Start with 1 (Alice's first move)
            // Add pairs of (remainder 1, remainder 2) stones that maintain sum % 3 != 0
            // Add all remainder 0 stones (they don't change sum % 3)
            int totalMoves = 1 + min(stoneCount[1], stoneCount[2]) * 2 + stoneCount[0];
          
            // If there are extra remainder 1 stones after pairing
            if (stoneCount[1] > stoneCount[2]) {
                stoneCount[1]--;
                totalMoves++;
            }
          
            // Alice wins if:
            // 1. Total moves is odd (Bob runs out of valid moves)
            // 2. The remaining stones don't force a draw (equal remainder 1 and 2)
            return (totalMoves % 2 == 1) && (stoneCount[1] != stoneCount[2]);
        };
      
        // Alice wins if she can win starting with remainder 1 OR remainder 2
        return checkAliceWins(count) || checkAliceWins(countSwapped);
    }
};
