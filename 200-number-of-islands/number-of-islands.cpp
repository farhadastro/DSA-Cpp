#include <vector>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty()) return 0;
        
        int num_islands = 0;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                // When we find land, count it, then sink the entire connected structure
                if (grid[r][c] == '1') {
                    num_islands++;
                    dfs(grid, r, c, rows, cols);
                }
            }
        }
        
        return num_islands;
    }
    
private:
    void dfs(vector<vector<char>>& grid, int r, int c, int rows, int cols) {
        // Base cases: Stop if out of bounds OR if the cell is water ('0')
        if (r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == '0') {
            return;
        }
        
        // Mutate the grid in-place to mark as visited (saves memory)
        grid[r][c] = '0';
        
        // Recursively traverse all 4 adjacent directions
        dfs(grid, r - 1, c, rows, cols); // Up
        dfs(grid, r + 1, c, rows, cols); // Down
        dfs(grid, r, c - 1, rows, cols); // Left
        dfs(grid, r, c + 1, rows, cols); // Right
    }
};