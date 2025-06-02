class Solution {
public:
    /*
     * DFS approach to count number of islands in a 2D grid.
     *
     * Summary:
     * - Treat the grid as a graph; land cells ('1') are nodes.
     * - For each unvisited land cell, perform DFS to "sink" the island by marking connected land as visited.
     * - Count how many times you initiate a DFS — each one represents a new island.
     *
     * Time: O(m * n), where m = rows, n = cols
     * Space: O(m * n) in the worst case (DFS recursion stack)
     */

    // DFS helper to mark all connected land ('1') as visited
    void dfs(vector<vector<char>> &grid, int r, int c) {
        // Return if out of bounds or if current cell is not land
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != '1') {
            return;
        }

        // Mark current cell as visited (or "sunk")
        grid[r][c] = '2';

        // Recursively visit all 4 neighboring cells (up, down, left, right)
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int ans = 0;

        // Scan entire grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // Found a new island
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);  // Sink the island
                    ans++;           // Count it
                }
            }
        }

        return ans;  // Total number of islands found
    }
};
