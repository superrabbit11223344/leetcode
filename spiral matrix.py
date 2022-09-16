# Leetcode Microsoft 54: Spiral Matrix

matrix_1 = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
matrix_2 = [[1, 2, 3, 4], [5, 6, 7, 8], [9, 10, 11, 12]]


def spiralWalk(matrix):
    if (len(matrix) == 0 or len(matrix[0]) == 0):
        return []
    m = len(matrix)
    n = len(matrix[0])
    left = 0
    right = n - 1
    top = 0
    bottom = m - 1
    output = []

    while (len(output) < m * n):
        for i in range(left, right+1):
            if len(output) < m * n:
                output.append(matrix[top][i])

        for i in range(top+1, bottom):
            if len(output) < m * n:
                output.append(matrix[i][right])

        for i in range(right, left-1, -1):
            if len(output) < m * n:
                output.append(matrix[bottom][i])

        for i in range(bottom-1, top, -1):
            if len(output) < m * n:
                output.append(matrix[i][left])

        left += 1
        right -= 1
        top += 1
        bottom -= 1

    return output


print(spiralWalk(matrix_1))
# [1, 2, 3, 6, 9, 8, 7, 4, 5]
print(spiralWalk(matrix_2))
# [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]
