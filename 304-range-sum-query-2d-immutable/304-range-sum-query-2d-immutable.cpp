class NumMatrix {
    vector<vector<int>> theSumMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->theSumMatrix = matrix;
            //vector<vector<int>>(matrix.size(),  vector<int>(matrix[0].size()));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 1; j < matrix[0].size(); j++) {
                theSumMatrix[i][j] += theSumMatrix[i][j - 1];
            }
        }
        
        for(int i = 1; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {                                                 theSumMatrix[i][j] += theSumMatrix[i-1][j];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = theSumMatrix[row2][col2];
        sum += (row1 > 0 && col1 > 0) ? theSumMatrix[row1-1][col1-1] : 0;
        sum -= (row1 > 0) ? theSumMatrix[row1-1][col2] : 0;
        sum -= (col1 > 0) ? theSumMatrix[row2][col1 - 1] : 0;
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */