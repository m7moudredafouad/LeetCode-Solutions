class Solution {
    
    bool countPalindromicBoth(string &s, vector<vector<int>>& saved, int start, int end) {
        if(start >= s.length()) return false;
        
        if(start >= end) return true;
        
        if(s[start] != s[end]) return false;
        
        return countPalindromicBoth(s, saved, start+1, end - 1);
    }
    
    int countPalindromic(string &s, vector<vector<int>>& saved, int start, int end) {
        if(start >= s.length() || end < 0 || end <= start) return 0;
        
        // cout << start << ": " << end << endl;
        
        if(saved[start][end] != -1) return 0;
        
        int areEqual = 0;
        if(s[start] == s[end]) {
            areEqual = 1;
        }
        
        int shiftLeft = countPalindromic(s, saved, start + 1, end);
        
        int shiftRight = countPalindromic(s, saved, start, end - 1);
        
        if(areEqual) {
            areEqual = countPalindromicBoth(s, saved, start + 1, end - 1);
        }

        
        saved[start][end] = shiftLeft + shiftRight + areEqual;
        return saved[start][end];
    }
public:
    int countSubstrings(string s) {
        vector<vector<int>> saved(s.length(), vector<int>(s.length(), -1));
        
        return countPalindromic(s, saved, 0, s.length()-1) + s.length();
    }
};