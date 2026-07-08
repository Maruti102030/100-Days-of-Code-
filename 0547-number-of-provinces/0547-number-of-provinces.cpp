class Solution {
private:
    void dfs(vector<vector<int>>& isConnected, int i, int n, vector<bool>& vis) {
        vis[i] = true;
        
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j] == 1 && !vis[j]) {
                dfs(isConnected, j, n, vis);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int province_count = 0;

        vector<bool> vis(n, false);
        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                province_count++;
                dfs(isConnected, i, n, vis);
            }
        }
        return province_count;
    }
};