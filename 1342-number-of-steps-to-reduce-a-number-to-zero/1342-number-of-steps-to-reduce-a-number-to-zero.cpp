class Solution {
public:
    int numberOfSteps(int n) {
        if(!n) return 0;
        int count = -1;
        
        while(n) {
            count += n & 1 ? 2 : 1;
            n = n >> 1;
        }
        
        return count;
    }
};