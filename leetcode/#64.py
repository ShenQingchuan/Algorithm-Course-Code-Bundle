from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        dSum = [[0 for _ in range(len(row))] for row in grid]

        # 先构建 dSum 数组的边行列:
        # 1. 行 =>
        tempSum = 0
        for col in range(len(grid[0])):
            tempSum += grid[0][col]
            dSum[0][col] = tempSum

        # 2. 列 =>
        tempSum = 0
        for row in range(len(grid)):
            tempSum += grid[row][0]
            dSum[row][0] = tempSum

        for row in range(1, len(grid)):
            for col in range(1, len(grid[0])):
                dSum[row][col] = min(dSum[row - 1][col], dSum[row][col - 1]) + grid[row][col]

        return dSum[-1][-1]


if __name__ == '__main__':
    myGrid = [
        [1, 3, 1],
        [1, 5, 1],
        [4, 2, 1]
    ]

    print(Solution().minPathSum(myGrid))
