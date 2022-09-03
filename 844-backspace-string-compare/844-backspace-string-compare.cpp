class Solution {
    string sanitize(string s) {
        string s1;   
        int j = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '#') {
                if(j > 0) {
                    s1.pop_back();
                    j--;                    
                }
                continue;
            }
            s1.push_back(s[i]);
            j++;
        }
        
        return s1;
    }
public:
    bool backspaceCompare(string s, string t) {
        return sanitize(s) == sanitize(t);
    }
};