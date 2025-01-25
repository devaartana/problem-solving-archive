class Solution {
public:
    std::vector<std::vector<bool>> visited;
    std::vector<int> row = {1, -1, 0, 0}, col = {0, 0, 1, -1};

    bool helper(std::vector<std::vector<char>>& board, std::string& word, int i,
                int j, int count) {

        if (word[count] != board[i][j]) {
            return false;
        }

        if (count == word.size() - 1) {
            return true;
        }

        visited[i][j] = true;

        for (int k = 0; k < 4; k++) {
            int nextRow = i + row[k];
            int nextCol = j + col[k];

            if (nextRow >= 0 && nextRow < board.size() && nextCol >= 0 &&
                nextCol < board[0].size() && !visited[nextRow][nextCol] &&
                helper(board, word, nextRow, nextCol, count + 1)) {
                return true;
            }
        }

        visited[i][j] = false;

        return false;
    }

    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        visited = std::vector<std::vector<bool>>(
            board.size(), std::vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (word[0] == board[i][j] && helper(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        return false;
    }
};
