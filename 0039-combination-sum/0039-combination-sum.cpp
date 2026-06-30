class Solution {
public:
    void findCombinations(int idx, int target, vector<int>& candidates, vector<int>& current, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(current);
            return;
        }
        
        if (idx == candidates.size() || target < 0) {
            return;
        }

        if (candidates[idx] <= target) {
            current.push_back(candidates[idx]);

            findCombinations(idx, target - candidates[idx], candidates, current, res); 
            current.pop_back();
        }

        findCombinations(idx + 1, target, candidates, current, res);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> current;
        findCombinations(0, target, candidates, current, res);
        return res;
    }
};