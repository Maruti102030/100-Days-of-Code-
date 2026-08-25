#include <string>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool isVowel(char c) {
        c = std::tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    std::string reverseVowels(std::string s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            // Advance left pointer to the next vowel
            while (left < right && !isVowel(s[left])) {
                left++;
            }
            // Move right pointer back to the previous vowel
            while (left < right && !isVowel(s[right])) {
                right--;
            }
            // Swap vowels and shrink the search window
            if (left < right) {
                std::swap(s[left], s[right]);
                left++;
                right--;
            }
        }

        return s;
    }
};