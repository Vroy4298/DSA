class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapS, mapT;
        for (int i = 0; i < s.length(); i++) {
            char sChar = s[i], tChar = t[i];

            if (mapS.count(sChar) && mapS[sChar] != tChar) return false;
            if (mapT.count(tChar) && mapT[tChar] != sChar) return false;

         
            mapS[sChar] = tChar;
            mapT[tChar] = sChar;
        }
        
        return true;
    }
};
