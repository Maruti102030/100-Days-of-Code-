#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        
        // 1. Frequency calculate karo
        for (int num : nums) {
            mp[num]++;
        }
        
        // 2. Buckets banao (index = frequency, value = list of numbers)
        vector<vector<int>> bucket(n + 1);
        for (auto it : mp) {
            int element = it.first;
            int freq = it.second;
            bucket[freq].push_back(element);
        }
        
        // 3. Highest frequency se iterate karke top k elements collect karo
        vector<int> res;
        for (int i = n; i >= 0 && res.size() < k; i--) {
            if (!bucket[i].empty()) {
                for (int num : bucket[i]) {
                    res.push_back(num);
                    if (res.size() == k) break;
                }
            }
        }
        
        return res;
    }
};