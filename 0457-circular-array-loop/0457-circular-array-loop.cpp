class Solution {
private:
    int n;
    
    // Helper function to calculate circular next index
    int getNext(vector<int>& nums, int i) {
        return (i + nums[i] % n + n) % n;
    }

public:
    bool circularArrayLoop(vector<int>& nums) {
        n = nums.size();
        
        for (int i = 0; i < n; i++) {
            // Skip already processed / invalid paths
            if (nums[i] == 0) continue;
            
            int slow = i;
            int fast = getNext(nums, i);
            
            // Fast & Slow step logic along with direction check
            // nums[i] * nums[fast] > 0 ensures movement is in same direction
            while (nums[i] * nums[fast] > 0 && nums[i] * nums[getNext(nums, fast)] > 0) {
                if (slow == fast) {
                    // Check if cycle length is 1 (self-loop)
                    if (slow == getNext(nums, slow)) {
                        break; // Invalid cycle, size 1
                    }
                    return true; // Valid cycle found!
                }
                
                slow = getNext(nums, slow);
                fast = getNext(nums, getNext(nums, fast));
            }
            
            // Mark the visited invalid path with 0 to optimize future iterations
            int j = i;
            int val = nums[i];
            while (nums[j] * val > 0) {
                int nextIdx = getNext(nums, j);
                nums[j] = 0;
                j = nextIdx;
            }
        }
        
        return false;
    }
};