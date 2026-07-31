class Solution {
public:
    int minimumPushes(string word) {
        vector<int> frequency(26, 0);
        for (char& ch : word) {
            frequency[ch - 'a']++;
        }
      
  
        sort(frequency.rbegin(), frequency.rend());
        int totalPushes = 0;
        for (int i = 0; i < 26; i++) {
            int pushesPerLetter = (i / 8) + 1;
            totalPushes += pushesPerLetter * frequency[i];
        }
      
        return totalPushes;
    }
};