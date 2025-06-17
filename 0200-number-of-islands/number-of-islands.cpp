class Solution {
public:
    /*
     * BFS approach to count number of islands in a 2D grid.
     *
     * Summary:
     * - Treat the grid as a graph; land cells ('1') are nodes.
     * - Use a queue to perform BFS from each unvisited land cell.
     * - For every land cell you visit, mark it as visited to prevent reprocessing.
     * - Count how many times you initiate a BFS — each one represents a new island.
     *
     * Time: O(m * n), where m = number of rows, n = number of columns
     * Space: O(min(m, n)) in the worst case for BFS queue
     */

    void bfs(vector<vector<char>>& grid, int row, int col) {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});
        grid[row][col] = '2';  // Mark as visited

        // Directions: up, down, left, right
        vector<pair<int, int>> directions = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int newRow = r + dr;
                int newCol = c + dc;

                if (newRow >= 0 && newRow < m &&
                    newCol >= 0 && newCol < n &&
                    grid[newRow][newCol] == '1') {
                    
                    grid[newRow][newCol] = '2';  // Mark visited
                    q.push({newRow, newCol});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;

        int islandCount = 0;
        int m = grid.size();
        int n = grid[0].size();

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    bfs(grid, i, j);  // Process entire island
                    islandCount++;   // Count new island
                }
            }
        }

        return islandCount;
    }
};