class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k <= 1) return 0;
        
        int n = nums.size();
        int low = 0;
        long long current_product = 1;
        int result = 0;
        
        for (int high = 0; high < n; high++) {
            current_product *= nums[high];
            
            while (current_product >= k && low <= high) {
                current_product /= nums[low];
                low++;
            }
            
            result += (high - low + 1);
        }
        
        return result;
    }
};