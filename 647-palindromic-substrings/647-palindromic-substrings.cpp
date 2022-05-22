class Solution {
    
    bool checkPalindromic(string &s, int start, int end) {
        if(start >= s.length()) return false;
        
        if(start >= end) return true;
        
        if(s[start] != s[end]) return false;
        
        return checkPalindromic(s, start+1, end - 1);
    }
    
    int countPalindromic(string &s, vector<vector<bool>>& saved, int start, int end) {
        if(start >= s.length() ||
           end <= start ||
           saved[start][end]) return 0;
                        
        
        saved[start][end] = true;
        int result = countPalindromic(s, saved, start + 1, end) +
                            countPalindromic(s, saved, start, end - 1);
        
        if(s[start] == s[end]) result += checkPalindromic(s, start + 1, end - 1);
        
        return result;
    }
public:
    int countSubstrings(string s) {
        vector<vector<bool>> saved(s.length(), vector<bool>(s.length(), false));
        
        return countPalindromic(s, saved, 0, s.length()-1) + s.length();
    }
};