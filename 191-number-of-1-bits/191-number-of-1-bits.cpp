class Solution {
public:
    int hammingWeight(uint32_t n) {
        uint8_t count = 0;
        while(n) {
            count += n & 0x1 ? 1 : 0;
            n = n >> 1;
        }
        return count;
    }
};