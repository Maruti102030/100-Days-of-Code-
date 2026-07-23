class Solution {
public:
    int totalFruit(std::vector<int>& fruits) {
        std::unordered_map<int, int> basket;
        int left = 0;
        int max_fruits = 0;
        int n = fruits.size();

        for (int right = 0; right < n; ++right) {
            basket[fruits[right]]++;

            while (basket.size() > 2) {
                basket[fruits[left]]--;
                if (basket[fruits[left]] == 0) {
                    basket.erase(fruits[left]);
                }
                left++;
            }


            max_fruits = std::max(max_fruits, right - left + 1);
        }

        return max_fruits;
    }
};