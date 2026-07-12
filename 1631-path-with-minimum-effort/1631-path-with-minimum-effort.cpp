class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};
        
        vector<vector<int>> eff_matrix(rows, vector<int>(cols, (int)1e9));
        
        priority_queue<pair<int, pair<int, int>>, 
            vector<pair<int, pair<int, int>>>, 
            greater<pair<int, pair<int, int>>>> pq;
        
        eff_matrix[0][0] = 0;
        pq.push({0, {0, 0}});
        
        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            
            int current_effort = curr.first;
            int r = curr.second.first;
            int c = curr.second.second;
            
            if (r == rows - 1 && c == cols - 1) {
                return current_effort;
            }
            if (current_effort > eff_matrix[r][c]) {
                continue;
            }
            for (int i = 0; i < 4; i++) {
                int nr = r + dx[i];
                int nc = c + dy[i];
                
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols) {
                    int new_effort = max(current_effort, abs(heights[r][c] - heights[nr][nc]));

                    if (new_effort < eff_matrix[nr][nc]) {
                        eff_matrix[nr][nc] = new_effort;
                        pq.push({new_effort, {nr, nc}});
                    }
                }
            }
        }
        return 0;
    }
};