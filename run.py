"""
public class MaxScorePath3D {

    public int findMaxScoreRecursive(int[][][] grid, int l, int r, int c) {
        int L = grid.length;
        int M = grid[0].length;
        int N = grid[0][0].length;

      
        if (l >= L || r >= M || c >= N) {
            return Integer.MIN_VALUE; // Represents an invalid or impossible path
        }

        int currentScore = grid[l][r][c];

        if (l == L - 1 && r == M - 1 && c == N - 1) {
            return currentScore; // Only the score of the destination cell
        }

        
        int path1 = findMaxScoreRecursive(grid, l + 1, r, c); // Move to next layer
        int path2 = findMaxScoreRecursive(grid, l, r + 1, c); // Move to next row
        int path3 = findMaxScoreRecursive(grid, l, r, c + 1); // Move to next column

        
        int maxFutureScore = Math.max(path1, Math.max(path2, path3));

        
        if (maxFutureScore == Integer.MIN_VALUE) {
            return Integer.MIN_VALUE; // This path doesn't lead to the destination
        }

        return currentScore + maxFutureScore;
    }
###
"""
grid = [[[]]]

def findMaxScore(grid):

    dp = {} # (l, r, c) -> max_score

    def findMaxScoreRecursive(l, r, c):
        key = (l, r, c)
        if key in dp:
            return dp[key]

        if l >= len(grid) or r >= len(grid[0]) or c >= len(grid[0][0]):
            return float('-inf')  # Invalid path

        current_score = grid[l][r][c]

        if l == len(grid) - 1 and r == len(grid[0]) - 1 and c == len(grid[0][0]) - 1:
            return current_score  # Only the score of the destination cell

        path1 = findMaxScoreRecursive(grid, l + 1, r, c)  # Move to next layer
        path2 = findMaxScoreRecursive(grid, l, r + 1, c)  # Move to next row
        path3 = findMaxScoreRecursive(grid, l, r, c + 1)  # Move to next column

        max_future_score = max(path1, path2, path3)

        if max_future_score == float('-inf'):
            return float('-inf')  # This path doesn't lead to the destination

        ans = current_score + max_future_score
        dp[key] = ans
        return dp[key]

    return findMaxScoreRecursive(0, 0, 0)


print(findMaxScore(grid))


dp = [[[]]]

L = len(grid)
R = len(grid[0])
C = len(grid[0][0])

dp = [[[0 for _ in range(C+1)] for _ in range(R+1)] for _ in range(L+1)]
bomb = [[[]]]

for l in range(1, L+1):
    for r in range(1, R+1):
        for c in range(1, C+1):
            if bomb[l-1][r-1][c-1]:
                dp[l][r][c] = float('-inf')
                continue

            dp[l][r][c] = grid[l-1][r-1][c-1] + max(
                dp[l-1][r][c],
                dp[l][r-1][c],
                dp[l][r][c-1]
            )

return dp[L][R][C]


