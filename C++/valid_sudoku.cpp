class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<int>> rows;
        unordered_map<int, unordered_set<int>> cols;
        map<pair<int, int>, unordered_set<int>> boxes;

        for (int i=0; i<9; i++){
            for (int j=0; j<9; j++){
                if (board[i][j] == '.'){
                    continue;
                }

                pair<int, int> box = {i / 3, j / 3};
                if (rows[i].contains(board[i][j]) || cols[j].contains(board[i][j]) || boxes[box].contains(board[i][j])){
                    return false;
                }

                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                boxes[box].insert(board[i][j]);
            }
        }

        return true;
    }
};
