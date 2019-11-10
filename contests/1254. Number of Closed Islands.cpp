//https://leetcode.com/contest/weekly-contest-162/problems/number-of-closed-islands/
class Solution {
    
    bool _boundaryReached = false;
    void checkDFS(vector<vector<int>>& grid, int i , int j) {
        // Out of bounds case.
        if ( i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size()) {
            return;
        }
        
        // Check if it's filled, simply return.
        if (grid[i][j] == 1 ) {
            return;
        }
        
        // If cell is already visited, using 2 to represent the visited cell.
        if ( grid[i][j] == 2) {
            return;
        }
        
        // Check if current cell is touching the boundary then it can;t be surronded by water.
        if ( grid[i][j] == 0)
        if ( i == 0 || j == 0 || i == grid.size() - 1 || j == grid[i].size() - 1) {
            // We can break, as we need to mark all neighbours with current cell which can't form a valid island.
            _boundaryReached = true;
        }
        
        // Mark the visited cell.
        grid[i][j] = 2;
        
        // Check all possible 4 neighbours.
        checkDFS(grid, i-1,j);
        checkDFS(grid, i+1,j);
        checkDFS(grid, i,j-1);
        checkDFS(grid, i,j+1);
    }
    
public:
    /**
    Idea is to do DFS for each not visited node. And see if we can reach to the boundary.
    If yes then that can't be closed island
    Else it is a closed island.
    Tip: Use the same grid for marking visited nodes, as possible values can be 0 or 1.
         Store 2 for the visited node mark. 
    **/
    int closedIsland(vector<vector<int>>& grid) {
        int result = 0;
        for(int i = 0; i<grid.size(); i++) {
            for(int j = 0 ; j < grid[i].size(); j++) {
                _boundaryReached = false;
                if ( grid[i][j] == 0) {
                    checkDFS(grid,i,j);
                    result += _boundaryReached ? 0 : 1;
                }
            }
        }
        return result;
    }
};
