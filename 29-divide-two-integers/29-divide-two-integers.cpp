class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        int8_t sign = dividend > 0 ? 1 : -1;
        sign *= divisor > 0 ? 1 : -1;
        
        long dvsr = abs(divisor),
             dvd = abs(dividend),
             quotient = 0;
        
        while(dvd >= dvsr) {
            long tmp = dvsr, m = 1;
            
            while((tmp <<= 1) <= dvd) {
                m <<= 1;
            }
            
            tmp >>= 1;
            dvd -= tmp;
            quotient += m;
        }
        
        return sign * quotient;
    }
};