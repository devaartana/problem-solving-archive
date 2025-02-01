class Solution {
public:
    void solve(std::vector<std::vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        std::vector<std::vector<bool>> visited(n, std::vector<bool>(m, false));
        std::vector<std::pair<int, int>> direction = {
            {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        std::queue<std::pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                visited[i][0] = true;
            }

            if (board[i][m - 1] == 'O') {
                q.push({i, m - 1});
                visited[i][m - 1] = true;
            }
        }

        for (int i = 0; i < m; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
                visited[0][i] = true;
            }

            if (board[n - 1][i] == 'O') {
                q.push({n - 1, i});
                visited[n - 1][i] = true;
            }
        }
        
        while (!q.empty()) {
            auto temp = q.front();
            q.pop();

            for (auto [nextRow, nextCol] : direction) {
                int row = nextRow + temp.first, col = nextCol + temp.second;

                if (row < 0 || row >= n || col < 0 || col >= m ||
                    visited[row][col] || board[row][col] == 'X') {
                    continue;
                }

                q.push({row, col});
                visited[row][col] = true;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O' && !visited[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
