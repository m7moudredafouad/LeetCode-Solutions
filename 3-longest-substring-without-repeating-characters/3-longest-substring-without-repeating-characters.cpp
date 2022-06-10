class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxTillNow = 0, curMax = 0, lastStart = 0;
        
        for(int i = 0; i < s.length(); i++) {
            curMax++;

            for(int j = lastStart; j < i; j++) {
                if(s[i] == s[j]) {
                    curMax = i - j;
                    lastStart = j+1;
                    break;
                }
            }
            
            if(maxTillNow < curMax) maxTillNow = curMax;
        }
        
        return maxTillNow ;
    }
};