#include <vector>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    int distributeCandies(std::vector<int>& candyType) {
        std::unordered_set<int> uniqueCandies(candyType.begin(), candyType.end());

        int maxAllowed = candyType.size() / 2;

        return std::min((int)uniqueCandies.size(), maxAllowed);
    }
};