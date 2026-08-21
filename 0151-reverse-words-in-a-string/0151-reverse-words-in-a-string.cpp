#include <string>
#include <sstream>
#include <vector>

class Solution {
public:
    std::string reverseWords(std::string s) {
        std::stringstream ss(s);
        std::string word, result = "";
        
        while (ss >> word) {
            if (result.empty()) {
                result = word;
            } else {
                result = word + " " + result;
            }
        }
        return result;
    }
};