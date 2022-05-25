class Solution {
    /*int theMax = INT_MIN;
    
    int compare(vector<int> &p1, vector<int> &p2) {
        if(p1[0] < p2[0] &&
           p1[1] < p2[1]) return 1;
        return 0;
    }
    
    int findMax(vector<vector<int>>& env, vector<int> &saved, int start) {
        if(start >= env.size()) return 0;
        
        if(saved[start] != -1) return saved[start]; 
        
        int currResult;
        int maxVal = 0;
        
        for(int i = start+1; i < env.size(); i++) {
            int x = findMax(env, saved, i);

            currResult = compare(env[start], env[i]);
            
            if(currResult) currResult += x;  

            maxVal = max(maxVal, currResult);            
        }
        
        saved[start] = maxVal;
        theMax = max(theMax, maxVal);
        
        return maxVal;
    }*/
    
    static int comparison(vector<int>& p1, vector<int>& p2) {
        return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] > p2[1]);
    }
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        sort(env.begin(), env.end(), comparison);
        
        vector<int> dp;
        for (auto e : env) {
            auto iter = lower_bound(dp.begin(), dp.end(), e[1]);
            if (iter == dp.end())
                dp.push_back(e[1]);
            else if (e[1] < *iter)
                *iter = e[1];
        }
        return dp.size();
    }
};