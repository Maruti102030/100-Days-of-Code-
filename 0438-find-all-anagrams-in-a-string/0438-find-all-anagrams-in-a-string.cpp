class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        std::vector<int> res;
        int n = s.size();
        int m = p.size();

        // Edge case: agar s ki length p se choti hai to anagrams milna impossible hai
        if (n < m) return res;

        std::vector<int> freq_p(26, 0);
        std::vector<int> freq_s(26, 0);

        // Step 1: p ki frequency aur s ki pehli window ki frequency store karo
        for (int i = 0; i < m; i++) {
            freq_p[p[i] - 'a']++;
            freq_s[s[i] - 'a']++;
        }

        // Step 2: Pehli window match karke dekho
        if (freq_p == freq_s) {
            res.push_back(0);
        }

        // Step 3: Fixed-size sliding window ko s par slide karo
        for (int i = m; i < n; i++) {
            // Naye character ko window me include karo
            freq_s[s[i] - 'a']++;
            
            // Purane character ko window se bahar nikalo (window size m maintain rakhne ke liye)
            freq_s[s[i - m] - 'a']--;

            // Frequency arrays compare karo
            if (freq_p == freq_s) {
                res.push_back(i - m + 1); // Starting index save karo
            }
        }

        return res;
    }
};