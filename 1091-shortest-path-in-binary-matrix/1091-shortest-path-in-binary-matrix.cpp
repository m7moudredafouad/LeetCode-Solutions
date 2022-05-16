class Solution {
    /*
    int min(int x, int y) {return x < y ? x : y;}
    int min(int x, int y, int z) {return min(min(x, y) , z);}
    
    int findPath(vector<vector<int>>& grid, int x, int y) {     // Dynamic programming will not work
        if(x < 0 || y < 0 || grid[x][y] != 0) return INT_MAX;
        if(x == 0 && y == 0) return grid[x][y] == 0 ? 1 : INT_MAX;
        
        int theMin = min(
            findPath(grid, x-1, y),
            findPath(grid, x, y-1),
            findPath(grid, x-1, y-1));
        
        return theMin != INT_MAX ? (1 + theMin) : INT_MAX;
    }*/
    // int minPath = findPath(grid, grid.size() - 1, grid.size() - 1);
    // return minPath == INT_MAX ? -1 : minPath;
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<vector<int>> myQ;
        vector<vector<int>> directions = {{1,1}, {0,1},{1,0},{0,-1},{-1,0},{-1, -1},{1, -1},{-1, 1}};
        myQ.push({0, 0, 1});
        int theMinPath = INT_MAX, size = grid.size()-1;
        vector<int> tmp;
        
        while(!myQ.empty()) {
            tmp = myQ.front();
            myQ.pop();
            
            if(grid[tmp[0]][tmp[1]] != 0) continue;
            
            if(tmp[2] <= theMinPath) theMinPath = tmp[2] + 1;
            
            if(tmp[0] == size && tmp[1] == size &&
               grid[tmp[0]][tmp[1]] == 0) return theMinPath - 1;
                        
            for(int i = 0; i < directions.size(); i++) {
                int x = tmp[0] + directions[i][0];
                int y = tmp[1] + directions[i][1];
                
                if(x > size || y > size || x < 0 || y < 0 || grid[x][y] != 0) continue;
                
                myQ.push({x, y, tmp[2]+1});
                grid[tmp[0]][tmp[1]] = 1;
            }
        }
        
        return -1;
    }
};