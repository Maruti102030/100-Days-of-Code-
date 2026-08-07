#include <string>
#include <algorithm>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.empty()) return "";

        int start = 0;
        int maxLength = 0;

        auto expandAroundCenter = [&](int left, int right) {
            while (left >= 0 && right < s.length() && s[left] == s[right]) {
                left--;
                right++;
            }
            // Length of the valid palindrome found: (right - 1) - (left + 1) + 1
            return right - left - 1;
        };

        for (int i = 0; i < s.length(); i++) {
            // Case 1: Odd length palindrome (center is s[i])
            int len1 = expandAroundCenter(i, i);
            
            // Case 2: Even length palindrome (center is between s[i] and s[i+1])
            int len2 = expandAroundCenter(i, i + 1);

            int len = std::max(len1, len2);

            // Update starting index and max length if a longer palindrome is found
            if (len > maxLength) {
                maxLength = len;
                start = i - (len - 1) / 2;
            }
        }

        return s.substr(start, maxLength);
    }
};