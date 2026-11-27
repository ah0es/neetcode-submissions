class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();

        // Check rows
        for (int i = 0; i < row; i++) {
            set<char> dub;

            for (int j = 0; j < col; j++) {
                if (board[i][j] != '.' && dub.find(board[i][j]) == dub.end()) {
                    dub.insert(board[i][j]);
                } 
                else if (board[i][j] != '.') {
                    return false;
                }
            }
        }

        // Check columns
        for (int j = 0; j < col; j++) {
            set<char> dub;

            for (int i = 0; i < row; i++) {
                if (board[i][j] != '.' && dub.find(board[i][j]) == dub.end()) {
                    dub.insert(board[i][j]);
                } 
                else if (board[i][j] != '.') {
                    return false;
                }
            }
        }

        // Check 3x3 boxes
        for (int boxRow = 0; boxRow < 9; boxRow += 3) {
            for (int boxCol = 0; boxCol < 9; boxCol += 3) {
                set<char> dub;

                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        char current = board[boxRow + i][boxCol + j];

                        if (current != '.' && dub.find(current) == dub.end()) {
                            dub.insert(current);
                        } 
                        else if (current != '.') {
                            return false;
                        }
                    }
                }
            }
        }

        return true;
    }
};