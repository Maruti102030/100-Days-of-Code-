#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int distributeCandies(std::vector<int>& candyType) {
        // Step 1: Count unique candy types using unordered_set
        std::unordered_set<int> uniqueCandies(candyType.begin(), candyType.end());
        
        // Step 2: Maximum candies Alice is allowed to eat
        int maxAllowed = candyType.size() / 2;
        
        // Step 3: Return the minimum of unique types and allowed capacity
        return std::min((int)uniqueCandies.size(), maxAllowed);
    }
};