#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> seen; 
        int start = 0, longest = 0; 

        for (int end = 0; end < s.length(); end++) {
            while (seen.count(s[end])) { 
                seen.erase(s[start]);
                start++; 
            }
            seen.insert(s[end]); 
            longest = max(longest, end - start + 1); 
        }

        return longest;
    }
};
