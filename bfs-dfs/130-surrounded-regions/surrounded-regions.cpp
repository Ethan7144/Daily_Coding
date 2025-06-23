class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        for(int i = 0; i < row; ++i){
            if(board[i][0] == 'O'){
                bfs(board, i, 0);
            } 
            if(board[i][col - 1] == 'O')
            {
                bfs(board, i, col - 1);
            }
        }
        for(int j = 0; j < col; ++j){
            if(board[0][j] == 'O'){
                bfs(board, 0, j);
            } 
            if(board[row - 1][j] == 'O')
            {
                bfs(board, row - 1, j);
            }
        }

        for(int i = 0; i < row; i++){
            for(int j = 0; j < col; j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                } else if(board[i][j] == 'T'){
                    board[i][j] = 'O';
                }
            }
        }
    }

    void bfs(vector<vector<char>>& board, int startRow, int startCol){
        int rows = board.size();
        int col = board[0].size();

        queue<pair<int, int>> q;
        q.push({startRow, startCol});
        board[startRow][startCol] = 'T';

        vector<pair<int, int>> directions = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for(auto [dx, dy] : directions){
                int newRow = x + dx;
                int newCol = y + dy;
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < col && board[newRow][newCol] == 'O'){
                    board[newRow][newCol] = 'T';
                    q.push({newRow, newCol});
                }
            }
        }
    }
};