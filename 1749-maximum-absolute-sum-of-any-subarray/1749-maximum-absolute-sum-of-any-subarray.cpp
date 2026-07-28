#include <vector>
#include <cmath>
#include <algorithm>

class Solution {
public:
    int maxAbsoluteSum(std::vector<int>& nums) {
        int max_sum = 0;
        int min_sum = 0;
        int curr_max = 0;
        int curr_min = 0;
        
        for (int num : nums) {
            // Maximum positive subarray sum
            curr_max = std::max(num, curr_max + num);
            max_sum = std::max(max_sum, curr_max);
            
            // Minimum negative subarray sum
            curr_min = std::min(num, curr_min + num);
            min_sum = std::min(min_sum, curr_min);
        }
        
        return std::max(max_sum, std::abs(min_sum));
    }
};