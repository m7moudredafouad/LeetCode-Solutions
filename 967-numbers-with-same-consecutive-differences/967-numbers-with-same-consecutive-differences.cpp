class Solution {
    void findTheNum(vector<int> &sol, int value, int prevNum, int n, int k) {
        if(n < 0)  {
            sol.push_back(value);
            return;
        }
                
        for(int i = 0; i < 10; i++) {
            if(abs(i - prevNum) == k) {
                findTheNum(sol, value+pow(10,n)*i, i, n-1, k);
            }
        }        
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> sol;
        for(int i = 1; i < 10; i++) {
            findTheNum(sol, pow(10, n-1) * i, i, n-2, k);
        }
        
        return sol;
    }
};