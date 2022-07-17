class Solution {
public:
    int kInversePairs(int n, int k) {
        vector<vector<int>> db(n+1, vector<int>(k+1, 0));
        
        db[0][0] = 1;
        for (int i = 1; i <= n; ++ i) {
            long long s = 0;
            for (int j = 0; j <= k; ++ j) {
                s += db[i - 1][j];
                if (j >= i) s -= db[i - 1][j - i];
                db[i][j] = ((long long)db[i][j] + s) % (1000000007); 
            }
        }
        return db[n][k];
    }
};