 class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;
        for (int i = 0; i < points.size(); i++) {
            int x = points[i][0];
            int y = points[i][1];
            int dist_sq = x * x + y * y;
            if (pq.size() < k) {
                pq.push({dist_sq, points[i]});
            }
            else if (dist_sq < pq.top().first) {
                pq.pop();
                pq.push({dist_sq, points[i]});
            }
        }
        vector<vector<int>> res;
        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};