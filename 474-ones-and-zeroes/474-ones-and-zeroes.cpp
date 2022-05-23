class Solution {
private:
    pair<int, int> countZerosOnes(string s) {
        pair<int, int> thePair(0, 0);
        for(int i =0; i < s.length(); i++) {
            if(s[i] == '0') {
                thePair.first++;
            } else {
                thePair.second++;
            }
        }
        return thePair;
    }
    
    int findTheMax(vector<string>& strs, vector<vector<vector<int>>> &saved, int m, int n, int curr) {
        if(curr >= strs.size() || m < 0 || n < 0) return 0;
                
        if(saved[m][n][curr] != -1) return saved[m][n][curr];
        
        pair<int, int> count = countZerosOnes(strs[curr]);
                
        int withCurr = INT_MIN;
        
        if(m >= count.first && n >= count.second){
            withCurr = 1 + findTheMax(strs, saved, m - count.first, n - count.second, curr+1);
        }

        int withoutCurr = findTheMax(strs, saved, m, n, curr+1);
        
        saved[m][n][curr] = max(withCurr, withoutCurr);
        return saved[m][n][curr];
    }
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> saved(m+1, vector<vector<int>>(n+1, vector<int>(strs.size(), -1)));
        return findTheMax(strs, saved, m, n, 0);
    }
};