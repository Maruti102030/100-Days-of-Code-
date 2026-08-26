#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {
public:
    int findShortestSubArray(std::vector<int>& nums) {
        std::unordered_map<int, int> count;
        std::unordered_map<int, int> first_idx;
        std::unordered_map<int, int> last_idx;
        
        int degree = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int val = nums[i];
            if (first_idx.find(val) == first_idx.end()) {
                first_idx[val] = i;
            }
            last_idx[val] = i;
            count[val]++;
            degree = std::max(degree, count[val]);
        }
        
        int min_length = nums.size();
        for (const auto& [val, freq] : count) {
            if (freq == degree) {
                int length = last_idx[val] - first_idx[val] + 1;
                min_length = std::min(min_length, length);
            }
        }
        
        return min_length;
    }
};