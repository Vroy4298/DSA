class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<vector<int>> charFrequency(2, vector<int>(26, 0));

        for (int i = 0; i < s1.size(); ++i) {
            int positionParity = i & 1;  
          

            ++charFrequency[positionParity][s1[i] - 'a'];
          
           
            --charFrequency[positionParity][s2[i] - 'a'];
        }
      

        for (int charIndex = 0; charIndex < 26; ++charIndex) {
            if (charFrequency[0][charIndex] != 0 || charFrequency[1][charIndex] != 0) {
                return false;
            }
        }
      
        return true;
    }
};