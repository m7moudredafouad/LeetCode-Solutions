class Solution {
    int countPaths(vector<vector<int>>& obstacleGrid, int x, int y) {
        if(x >= obstacleGrid.size() ||
           y >= obstacleGrid[0].size() ||
           x < 0 || y < 0) return 0;
        
        if(obstacleGrid[x][y] == 1) return 0;
        
        
        if(x == obstacleGrid.size() - 1 &&
           y == obstacleGrid[0].size() -1) return 1;
        
        if(obstacleGrid[x][y] < 0) return -1*obstacleGrid[x][y];
        
        int right = countPaths(obstacleGrid, x, y + 1);
        int down = countPaths(obstacleGrid, x + 1, y);
        
        if(right > 0 || down > 0)  obstacleGrid[x][y] = -(right+down);
        return right + down;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        return countPaths(obstacleGrid, 0, 0);
    }
};