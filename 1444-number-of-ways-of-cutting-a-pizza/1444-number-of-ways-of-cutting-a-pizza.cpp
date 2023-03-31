class Solution {
public:
    long long MOD = 1000000007;
    bool hasApple(vector<string>& grid, int startRow, int endRow, int startCol, int endCol) {
        for (int i = startRow; i <= endRow; i++) {
            for (int j = startCol; j <= endCol; j++) {
                if (grid[i][j] == 'A') 
                    return true;
            }
        }
        return false;
    }
    int ways(vector<string>& grid, int k) {
        int numRows = grid.size(), numCols = grid[0].size();
        vector<vector<vector<int>>> dp(numRows, vector<vector<int>>(numCols, vector<int>(k, 0)));
        
        // Base case
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numCols; j++) {
                if (hasApple(grid, i, numRows - 1, j, numCols - 1)) {
                    dp[i][j][0] = 1;
                }
            }
        }
        
        // Fill up the DP table
        for (int cut = 1; cut < k; cut++) {
            for (int i = 0; i < numRows; i++) {
                for (int j = 0; j < numCols; j++) {
                    long long ans = 0;
                    //make a cut below the row with index 'row'
                    for (int row = i; row < numRows - 1; row++) {
                        if (hasApple(grid, i, row, j, numCols - 1) && dp[row + 1][j][cut - 1]) {
                            ans = (ans + dp[row + 1][j][cut - 1]) % MOD;
                        }
                    }
                    //make a cut to the right of column with index 'col'
                    for (int col = j; col < numCols - 1; col++) {
                        if (hasApple(grid, i, numRows - 1, j, col) && dp[i][col + 1][cut - 1]) {
                            ans = (ans + dp[i][col + 1][cut - 1]) % MOD;
                        }
                    }
                    dp[i][j][cut] = ans;
                }
            }
        }
        
        return dp[0][0][k - 1];
    }
};