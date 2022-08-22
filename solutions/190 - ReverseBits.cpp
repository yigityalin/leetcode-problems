class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t reversed = 0, count = 31;
        while (count) {
            reversed += n & 1;
            n >>= 1;
            reversed <<= 1;
            count--;
        }
        reversed += n & 1;
        return reversed;
    }
};