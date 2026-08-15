class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int ROWS = matrix.size(); int COLS = matrix[0].size();
        int t = 0; int b = ROWS - 1;

        while (t<=b){
            int midRow = t + (b - t) / 2;

            if (matrix[midRow][0] <= target && target <= matrix[midRow][COLS - 1]){
                int l = 0; int r = COLS - 1;

                while (l<=r){
                    int midCol = l + (r - l) / 2;
                    if (matrix[midRow][midCol] == target){
                        return true;
                    }

                    else if (matrix[midRow][midCol] < target){l = midCol + 1;}
                    else{r = midCol - 1;}
                }
                return false;
            }

            else if (matrix[midRow][0] > target){b = midRow - 1;}
            else {t = midRow + 1;}
        }
        return false;
    }
};
