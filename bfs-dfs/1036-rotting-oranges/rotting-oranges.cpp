class Solution {
public:
    /*
     * Problem: Rotting Oranges (LeetCode 994)
     * Approach: Multi-source Breadth-First Search (BFS)
     *
     * Summary:
     * - Each cell in the grid can be empty (0), a fresh orange (1), or a rotten orange (2).
     * - Every minute, any fresh orange adjacent (up/down/left/right) to a rotten orange becomes rotten.
     * - The goal is to return the minimum number of minutes until no fresh oranges remain.
     * - If it's impossible to rot all fresh oranges, return -1.
     *
     * Core Strategy:
     * - Use a queue to track all initially rotten oranges (multi-source BFS).
     * - Use a fresh counter to track how many fresh oranges are left.
     * - At each minute (BFS level), rot all adjacent fresh oranges and enqueue them.
     * - Increment time only after each full layer is processed.
     *
     * Time Complexity: O(m * n)
     * - We visit each cell at most once.
     *
     * Space Complexity: O(m * n)
     * - Queue can contain up to all cells in the grid in the worst case.
     */
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        int fresh = 0;

        // Step 1: Scan grid for rotten and fresh oranges
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j}); // track rotten
                } else if (grid[i][j] == 1) {
                    fresh++;       // count fresh
                }
            }
        }

        // Step 2: BFS to spread rot minute by minute
        int mins = 0;
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        while (!q.empty() && fresh > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [r, c] = q.front(); q.pop();

                for (auto [dr, dc] : directions) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;    // rot it
                        q.push({nr, nc});    // enqueue for next minute
                        fresh--;            // reduce fresh count
                    }
                }
            }
            mins++; // one minute passes
        }

        // Step 3: Final check
        return (fresh == 0) ? mins : -1;
    }
};
