class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        ROWS, COLS = len(matrix), len(matrix[0])
        t, b = 0, ROWS - 1

        while t <= b:
            midRow = t + (b - t) // 2
            if matrix[midRow][0] <= target <= matrix[midRow][COLS - 1]:
                l, r = 0, COLS - 1
                while l <= r:
                    midCol = l + (r - l) // 2
                    print(midRow, midCol)
                    if matrix[midRow][midCol] == target:
                        return True
                    elif matrix[midRow][midCol] < target:
                        l = midCol + 1
                    else:
                        r = midCol - 1
                return False
            elif matrix[midRow][0] > target:
                b = midRow - 1
            else:
                t = midRow + 1
        return False
