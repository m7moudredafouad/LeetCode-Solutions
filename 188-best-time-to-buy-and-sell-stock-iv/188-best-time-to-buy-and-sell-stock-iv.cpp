class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        if (k >= prices.size() / 2) {
            int profit = 0;
            for (int i = 1; i < prices.size(); i++)
                if (prices[i] > prices[i - 1]) profit += prices[i] - prices[i - 1];
            return profit;
        }
        
        
        vector<vector<int>> db(k+1, vector<int>(prices.size()));
        for (int i = 1; i <= k; i++) {
            int tmpMax =  -prices[0];
            for (int j = 1; j < prices.size(); j++) {
                db[i][j] = max(db[i][j - 1], prices[j] + tmpMax);
                tmpMax =  max(tmpMax, db[i - 1][j - 1] - prices[j]);
            }
        }
        
        return db[k][prices.size() - 1];
    }
};