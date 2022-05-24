class Solution {
public:
    int max(int a, int b) {return a > b ? a : b;}
    int longestValidParentheses(string s) {
        stack<int> myStack;
        int maxValid = 0, lastEmpty = -1;

        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(') {
                myStack.push(i);
            } else {
                
                if(myStack.empty()) {
                    lastEmpty = i;
                    continue;
                } 
                
                myStack.pop();
                if(myStack.empty()) 
                    maxValid = max(maxValid, i - lastEmpty);
                else
                    maxValid = max(maxValid, i - myStack.top());
            }
            
            
        }     
        
        return maxValid;
    }
};