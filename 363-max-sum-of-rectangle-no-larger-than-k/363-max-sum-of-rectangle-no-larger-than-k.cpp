class Solution {
  void addColumnToVector(vector<int> &addHere, vector<vector<int>> & addFrom, int colIndex) {
    for(int i = 0; i < addHere.size(); i++) {
      addHere[i] += addFrom[i][colIndex];
    }
  }
  
  int findMax(vector<int> &sums, int k) {
    signed int currentSum, maxSum = INT_MIN;
    for(int i = 0; i < sums.size(); i++) {
      currentSum = 0;
      for(int j = i; j < sums.size(); j++) {
        currentSum += sums[j];
        if(currentSum <= k) {
          if(currentSum == k) return k;
          if(currentSum > maxSum) maxSum = currentSum;
        }
      }
    }
    return maxSum;
  }
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
      signed int currentMax, maxSum = INT_MIN;
      
      for(int i = 0; i < matrix[0].size(); i++) {
        vector<int> sums(matrix.size(), 0);  // Create new vector to hold the sums
        currentMax = INT_MIN;

        for(int j = i; j < matrix[0].size(); j++) {
          addColumnToVector(sums, matrix, j); // Add current column to the created vector
      
          currentMax = findMax(sums, k);// find the max sum of the new vector
          
          if(currentMax == k) return k;
          if(currentMax > maxSum) maxSum = currentMax;
        }
      }
      
      return maxSum;
    }
};