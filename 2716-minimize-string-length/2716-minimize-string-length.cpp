#include <string>
#include <unordered_set>

class Solution {
public:
    int minimizedStringLength(std::string s) {
        // Collect all unique characters in a set
        std::unordered_set<char> unique_chars(s.begin(), s.end());
        
        // The size of the set represents the minimum possible length
        return unique_chars.size();
    }
};