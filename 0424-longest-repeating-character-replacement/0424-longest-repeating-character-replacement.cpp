class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int low = 0;
        int high = 0;
        int res = 0;
        unordered_map<char, int> f;
        for (high=0; high<n; high++){
            f[s[high]]++;
            int len = high - low + 1;
            int maxint = find(f);
            int diff = len - maxint;

            while(diff>k){
                f[s[low]]--;
                if (f[s[low]]==0){
                    f.erase(s[low]);
                }
                low++;
                maxint = find(f);
                len = high - low + 1;
                diff = len - maxint;
            }
            len = high - low + 1;
            res = max(res, len);
        }
        return res;

    }
    int find(unordered_map<char, int>& f){
        int maxi = 0;
        for (auto x : f){
            maxi = max(maxi, x.second);
        }
        return maxi;
    }
};