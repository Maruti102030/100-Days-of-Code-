class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int closestSum = nums[0] + nums[1] + nums[2];
        int n = nums.size();
        for (int i = 0; i<n-2; i++){
            int left = i+1;
            int right = n-1;
            while(left<right){
                int Sum = nums[i] + nums[left] + nums[right];
                if (Sum < target){
                    left++;
                }
                else if(Sum>target){
                    right--;
                }
                if (Sum == target) {
                    return target;
                }
                if (abs(Sum - target) < abs(closestSum - target)) {
                    closestSum = Sum;
                }
            }
            
        }
        return closestSum;

    }
};