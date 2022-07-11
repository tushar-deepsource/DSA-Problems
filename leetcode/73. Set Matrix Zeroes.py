class Solution:

    @staticmethod
    def setZeroes(matrix: List[List[int]]) -> None:
        m = len(matrix)
        n = len(matrix[0])
        locations = []
        for i in range(m):
            for j in range(n):
                if matrix[i][j] == 0:
                    locations.append([i, j])
        for location in locations:
            for i in range(m):
                matrix[i][location[1]] = 0
            for j in range(n):
                matrix[location[0]][j] = 0
