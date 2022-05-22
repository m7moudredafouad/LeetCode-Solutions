class Solution {
    
    bool checkPalindromic(string &s, int start, int end) {
        if(start >= s.length()) return false;
        
        if(start >= end) return true;
        
        if(s[start] != s[end]) return false;
        
        return checkPalindromic(s, start+1, end - 1);
    }
    
    int countPalindromic(string &s, vector<vector<int>>& saved, int start, int end) {
        if(start >= s.length() ||
           end <= start ||
           saved[start][end] != -1) return 0;        
        
        saved[start][end] = countPalindromic(s, saved, start + 1, end) +
                            countPalindromic(s, saved, start, end - 1);
        
        if(s[start] == s[end]) saved[start][end] += checkPalindromic(s, start + 1, end - 1);
        
        return saved[start][end];
    }
public:
    int countSubstrings(string s) {
        vector<vector<int>> saved(s.length(), vector<int>(s.length(), -1));
        
        return countPalindromic(s, saved, 0, s.length()-1) + s.length();
    }
};