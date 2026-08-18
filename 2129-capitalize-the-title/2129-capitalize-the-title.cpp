#include <string>
#include <cctype>

class Solution {
public:
    std::string capitalizeTitle(std::string title) {
        int n = title.size();
        int i = 0;
        
        while (i < n) {
            int j = i;
            // Find the boundary of the current word
            while (j < n && title[j] != ' ') {
                title[j] = std::tolower(title[j]);
                j++;
            }
            
            int len = j - i;
            // Capitalize first character if word length >= 3
            if (len > 2) {
                title[i] = std::toupper(title[i]);
            }
            
            i = j + 1; // Move to the start of the next word
        }
        
        return title;
    }
};