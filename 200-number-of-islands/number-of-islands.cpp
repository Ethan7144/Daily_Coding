class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size();
        int col = grid[0].size();
        int count = 0;
            for(int i = 0; i < rows; i++){
                for(int j = 0; j < col; j++){
                    if(grid[i][j] == '1'){
                        count++;
                        bfs(grid, i, j);
                    }
                }
            }

        return count;
    }

    void bfs(vector<vector<char>>& grid, int startRow, int startCol) {
        int rows = grid.size();
        int col = grid[0].size();

        queue<pair<int, int>> q;
        q.push({startRow, startCol});
        grid[startRow][startCol] = '0'; 

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(auto [dx, dy] : directions){
                int newRow = x + dx;
                int newCol = y + dy;
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < col && grid[newRow][newCol] == '1'){
                    grid[newRow][newCol] = '0';
                    q.push({newRow, newCol});
                }
            }
        }
    }
};