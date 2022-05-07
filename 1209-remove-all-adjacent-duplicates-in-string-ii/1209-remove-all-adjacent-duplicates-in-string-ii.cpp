class Solution {
    stack<pair<char, int>> myStack;
public:
    string removeDuplicates(string s, int k) {
        int sLen = s.length();
        pair<char, int> lastInserted;
        
        while(--sLen >= 0) {
            if(myStack.empty()) {
                myStack.push(make_pair(s[sLen], 1));
                continue;
            }
            
            lastInserted = myStack.top();
            if(lastInserted.first != s[sLen]) {
                myStack.push(make_pair(s[sLen], 1));
                continue;
            }            
            
            if(lastInserted.second == (k - 1)) {
                while(lastInserted.second--) myStack.pop();
            } else {
                myStack.push(make_pair(s[sLen], lastInserted.second + 1));
            }
        }
        
        string ss;
        while(!myStack.empty()) {
            lastInserted = myStack.top();
            ss += lastInserted.first;
            myStack.pop();
        }
        
        
        return ss;
    }
};