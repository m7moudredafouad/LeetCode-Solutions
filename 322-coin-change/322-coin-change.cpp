class Solution {
    /*
    // This solution gives ==> Time Limit Exceeded
    int countCoins(vector<int>& coins, int curr, int target) {
        if(target == 0) return 0;
        if(curr < 0 || target < 0) return INT_MAX - 1;
        
        if(coins[curr] > target) {
            return countCoins(coins, curr - 1, target);
        } else {
            return min(countCoins(coins, curr - 1, target),
                       countCoins(coins, curr, target  - coins[curr]) + 1
                      );
        }
        
    }*/
public:
    int coinChange(vector<int>& coins, int amount) {
        sort(coins.begin(), coins.end());
        
        vector<int> dp(amount+1, INT_MAX-1);
        dp[0] = 0;
        
        for(int i = 1; i <= amount; i++) {
            for(int j = 0; j < coins.size(); j++) {
                if(coins[j] > i) break;
                
                dp[i] = min(dp[i], dp[i - coins[j]]+1);
            }
        }
        
        return dp[amount] == INT_MAX-1 ? -1 : dp[amount];
    }
};