#include <cctype>  
#include <string>

class Solution {
public:
    bool isPalindrome(std::string s) {
        int left = 0, right = s.length() - 1;

        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;  
            }
            while (left < right && !isalnum(s[right])) {
                right--; 
            }
            if (tolower(s[left]) != tolower(s[right])) {
                return false;  
            }
            left++;
            right--;
        }
        return true;
    }
};
