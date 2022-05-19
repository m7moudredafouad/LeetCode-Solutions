class Solution {
  vector<vector<int>> trackPaths;
  int max(int a, int b) {return a > b ? a : b;}
  int max(int a, int b, int c, int d) {return max(max(a, b), max(c, d));}

  int findMaxPathFromPoint(vector<vector<int>>& matrix, int lastEl, int i, int j) {
    if(i >= matrix.size() || i < 0 ||
       j >=  matrix[0].size() || j < 0) return 0;
    
    if(matrix[i][j] <= lastEl) return 0;
    
    if(trackPaths[i][j] != -1) return trackPaths[i][j];
    
    int currPathLen = 1 + max(
        findMaxPathFromPoint(matrix, matrix[i][j], i + 1, j),
        findMaxPathFromPoint(matrix, matrix[i][j], i - 1, j), 
        findMaxPathFromPoint(matrix, matrix[i][j], i, j + 1), 
        findMaxPathFromPoint(matrix, matrix[i][j], i, j - 1) 
    );
    
    trackPaths[i][j] = currPathLen;

    
    return currPathLen;
    
  }
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
      int maxPath = INT_MIN;
      int currPathLen = 0;
      trackPaths = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size(), -1));
      
      for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[0].size(); j++) {          
          maxPath = max(maxPath, findMaxPathFromPoint(matrix, INT_MIN, i, j));
        }
      }
      
      return maxPath;
    }
};