class Solution {
private:
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};

    bool valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& a) {
        int n = a.size();
        int m = a[0].size();
        std::queue<std::pair<int, int>> q;
        int fresh = 0;
        int time = 0;

        // Step 1: Initial rotten oranges ko queue mein dalein aur fresh count karein
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i][j] == 2) {
                    q.push({i, j});
                } else if (a[i][j] == 1) {
                    fresh++;
                }
            }
        }

        // Step 2: Multi-source BFS chalayen
        while (!q.empty() && fresh > 0) {
            time++;
            int s = q.size();
            
            // Is loop ke ANDAR hi har ek element nikal kar process hoga
            while (s--) {
                pair<int, int> p = q.front(); // 1. Pehle element read karo
                q.pop();                      // 2. Fir pop karo
                
                int r = p.first;
                int c = p.second;

                // 3. Uske padosiyon ko check karo (Yeh bhi isi loop ke andar rahega)
                for (int k = 0; k < 4; k++) {
                    int row = r + x[k];
                    int col = c + y[k];

                    if (valid(row, col, n, m) && a[row][col] == 1) {
                        q.push({row, col});
                        a[row][col] = -2; // Rotten mark kiya
                        fresh--;
                    }
                }
            } // <-- s-- wala loop yahan khatam hoga
        }

        if (fresh > 0) {
            return -1;
        }
        
        return time;
    }
};