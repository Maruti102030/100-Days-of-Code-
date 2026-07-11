class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& edge : times) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
        }
        vector<int> dist(n + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        dist[k] = 0;
        pq.push({0, k});

        while (!pq.empty()) {
            int currentTime = pq.top().first;
            int currNode = pq.top().second;
            pq.pop();

            if (currentTime > dist[currNode]) continue;

            for (auto& neighbor : adj[currNode]) {
                int nextNode = neighbor.first;
                int travelTime = neighbor.second;

                if (currentTime + travelTime < dist[nextNode]) {
                    dist[nextNode] = currentTime + travelTime;
                    pq.push({dist[nextNode], nextNode});
                }
            }
        }
        int maxTime = 0;
        for (int i = 1; i <= n; i++) {
            if (dist[i] == INT_MAX) return -1; 
            maxTime = max(maxTime, dist[i]);
        }

        return maxTime;
    }
};