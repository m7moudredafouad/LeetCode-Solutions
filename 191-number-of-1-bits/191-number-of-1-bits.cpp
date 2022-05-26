class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint32_t x = n;
        int count = 0;
        while(x) {
            count += x & 0x1 ? 1 : 0;
            x = x >> 1;
        }
        return count;
    }
};