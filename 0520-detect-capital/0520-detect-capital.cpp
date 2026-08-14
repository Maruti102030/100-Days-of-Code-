class Solution {
public:
    bool detectCapitalUse(string word) {
        int capitalCount = 0;
        int n = word.length();

        for (char c : word) {
            if (isupper(c)) {
                capitalCount++;
            }
        }

        // Case 1: All uppercase letters (e.g., "USA")
        // Case 2: All lowercase letters (e.g., "leetcode")
        if (capitalCount == n || capitalCount == 0) {
            return true;
        }

        // Case 3: Only the first letter is uppercase (e.g., "Google")
        if (capitalCount == 1 && isupper(word[0])) {
            return true;
        }

        // Any other mixed case is invalid (e.g., "FlaG")
        return false;
    }
};