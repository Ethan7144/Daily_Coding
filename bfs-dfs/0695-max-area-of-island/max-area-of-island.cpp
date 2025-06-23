class Solution {
public:
    /*
     * Problem: Max Area of Island (LeetCode 695)
     * Approach: Depth-First Search (DFS) on a 2D grid
     *
     * Summary:
     * - Each cell with a value of 1 represents land; 0 represents water.
     * - An island is a group of adjacent 1’s (up/down/left/right).
     * - The task is to find the maximum area (number of connected 1’s) of any island in the grid.
     *
     * Core Idea:
     * - Traverse the entire grid.
     * - When we encounter land (1), we perform a DFS to calculate the area of that island.
     * - We return the maximum area found across all islands.
     *
     * DFS Details:
     * - The DFS function returns the area of an island starting from a given cell.
     * - We mark visited land cells by changing their value to 2 (to avoid revisiting).
     * - The DFS explores in 4 directions and sums up the total land area.
     *
     * Time Complexity: O(m * n)
     * - Each cell is visited at most once.
     *
     * Space Complexity: O(m * n)
     * - Due to the call stack in the worst case (grid is entirely land).
     */

    int dfs(vector<vector<int>>& grid, int r, int c) {
        // Base case: out of bounds or water or already visited
        if (r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] != 1) {
            return 0;
        }

        // Mark this land cell as visited
        grid[r][c] = 2;

        // Start area count with this cell
        int area = 1;

        // Explore all 4 neighbors and accumulate their area
        area += dfs(grid, r + 1, c); // down
        area += dfs(grid, r - 1, c); // up
        area += dfs(grid, r, c + 1); // right
        area += dfs(grid, r, c - 1); // left

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        if (grid.empty()) return 0;

        int maxArea = 0;

        // Traverse each cell in the grid
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                // When we find unvisited land, compute the area via DFS
                if (grid[i][j] == 1) {
                    int area = dfs(grid, i, j);
                    maxArea = max(maxArea, area);
                }
            }
        }

        return maxArea; // Return the largest island area found
    }
};
