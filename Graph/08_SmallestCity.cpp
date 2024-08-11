// lc-1334
// tc : O(N^3)
// sc : O(N^2)

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        // Floyd-Warshall algorithm
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            dist[i][i] = 0;
        }

        // Populate the distance matrix
        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            dist[u][v] = min(dist[u][v], w);
            dist[v][u] = min(dist[v][u], w);
        }

        // Floyd-Warshall algorithm
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        int mini = INT_MAX;
        int res = -1;

        // Find the required city
        for (int i = 0; i < n; i++) {
            int counter = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && dist[i][j] <= distanceThreshold) {
                    counter++;
                }
            }

            if (counter <= mini ) {
                mini = counter;
                res = i;
            }
        }

        return res;
    }
