class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int count = 0;
        
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 1; j < matrix[0].size(); j++)
                matrix[i][j] += matrix[i][j - 1];

        unordered_map<int, int> counter;
        
        for (int i = 0; i < matrix[0].size(); i++) {
            for (int j = i; j < matrix[0].size(); j++) {
                counter.clear();
                counter[0] = 1;
                int sum = 0;
                for (int k = 0; k < matrix.size(); k++) {
                    
                    sum += matrix[k][j] - (i > 0 ? matrix[k][i - 1] : 0);
                    
                    count += counter.find(sum - target) != counter.end() ? counter[sum - target] : 0;
                    
                    counter[sum]++;
                }
            }
        }
        return count;
    }
};