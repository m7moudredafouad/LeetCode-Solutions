class Solution {    
    bool isValid( vector<string> &tmp,int x, int y, int n) {
        for(int i = 0; i < n; i++) {
            if(tmp[i][y] == 'Q') return false;
        }

        for(int i = x, j = y; i >= 0 && j < n; i--, j++) {
            if(tmp[i][j] == 'Q') return false;
        }

        for(int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
            if(tmp[i][j] == 'Q') return false;
        }
        
        return true;
    }
    
    void solveQueen(vector<vector<string>> &sol, vector<string> &tmp,int index, int n) {
        if(index == n) {
            sol.push_back(tmp);
            return;
        }
        for(int i = 0; i < n; i++) {
            if(isValid(tmp, index, i, n)) {
                tmp[index][i] = 'Q';
                solveQueen(sol, tmp, index+1, n);
                tmp[index][i] = '.';            
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> sol;
        vector<string> tmp(n, string(n, '.'));
        solveQueen(sol, tmp, 0, n);
        return sol;
    }
};




