class Solution {
    long findThePaths(int m, int n, int maxMove, int startRow, int startColumn, vector<vector<vector<int>>> &db) {
        if(maxMove < 0) return 0;

        if(startRow >= m || startColumn >= n ||
          startRow < 0 || startColumn < 0 ) return 1;
        
        
        if(db[startRow][startColumn][maxMove] != -1) return db[startRow][startColumn][maxMove];
        
        return db[startRow][startColumn][maxMove] =
            (findThePaths(m, n, maxMove - 1, startRow, startColumn + 1, db) +
            findThePaths(m, n, maxMove - 1, startRow + 1, startColumn, db) +
            findThePaths(m, n, maxMove - 1, startRow, startColumn - 1, db) +
            findThePaths(m, n, maxMove - 1, startRow - 1, startColumn, db)) % (1000000007);
    }
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> db(m+1, vector<vector<int>>(n+1, vector<int>(maxMove+1, -1)));
        return findThePaths(m, n, maxMove, startRow, startColumn, db);
    }
};