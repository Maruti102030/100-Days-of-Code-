class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int first = findBound(nums, target, true);
        if (first == -1) {
            return {-1, -1};
        }
        
        int last = findBound(nums, target, false);
        return {first, last};
    }

private:
    int findBound(std::vector<int>& nums, int target, bool isFirst) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (nums[mid] == target) {
                ans = mid; 
                
                if (isFirst) {
                    end = mid - 1; 
                } else {
                    start = mid + 1;
                }
            } 
            else if (nums[mid] < target) {
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        return ans;
    }
};