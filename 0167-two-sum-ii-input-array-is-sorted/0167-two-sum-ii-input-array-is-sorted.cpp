class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        while (left<right){
            int curr_sum = nums[left] + nums[right];
            if (curr_sum==target){
                return {left+1, right+1};
            }
            else if (curr_sum<target){
                left++;
            }
            else{
                right--;
            }
        }
        return {};
    }
};