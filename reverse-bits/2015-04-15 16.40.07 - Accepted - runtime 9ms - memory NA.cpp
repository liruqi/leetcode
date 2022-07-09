class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ret = 0;
        uint32_t b = 1;
        int p = 32;
        for (;b;b<<=1) {
            p --;
            if (n & b) {
                ret |= (1<<p);
            }
        }
        return ret;
    }
};