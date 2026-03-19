#include <bits/stdc++.h>
using namespace std;

int numberOfSubmatrices(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    
    // Initialize countGrid with proper size
    vector<vector<pair<int, int>>> countGrid(n, vector<pair<int, int>>(m, {0, 0}));
    
    // Build prefix sum grid (counts from (0,0) to (i,j))
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            // Start with counts from top and left
            int count_x = 0;
            int count_y = 0;
            
            // Add current cell
            if (grid[i][j] == 'X')
                count_x++;
            if (grid[i][j] == 'Y')  // Fixed: uppercase Y
                count_y++;
            
            // Add from top cell (if exists)
            if (i > 0)
            {
                count_x += countGrid[i-1][j].first;
                count_y += countGrid[i-1][j].second;
            }
            
            // Add from left cell (if exists)
            if (j > 0)
            {
                count_x += countGrid[i][j-1].first;
                count_y += countGrid[i][j-1].second;
            }
            
            // Subtract diagonal (if both exist) to avoid double counting
            if (i > 0 && j > 0)
            {
                count_x -= countGrid[i-1][j-1].first;
                count_y -= countGrid[i-1][j-1].second;
            }
            
            countGrid[i][j] = {count_x, count_y};
        }
    }
    
    // Count valid submatrices (from (0,0) to (i,j))
    int result = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x = countGrid[i][j].first;
            int y = countGrid[i][j].second;
            
            // Must have at least one X and equal X and Y
            if (x > 0 && x == y)
                result++;
        }
    }
    
    return result;
}

int main()
{
    vector<vector<char>> grid = {
        {'X', 'Y', '.'},
        {'Y', '.', '.'}
    };
    
    cout << numberOfSubmatrices(grid) << endl;  // Output: 3
    
    return 0;
}