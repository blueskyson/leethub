class Solution {
public:
    int getSum(int a, int b) {
        int c = 0;  // carry bit
        int mask = 1;
        int result = 0;
        while (1) {
            int ba = a & mask;
            int bb = b & mask;
            int bc = c & mask;
            result |= (ba ^ bb ^ bc);
            if (mask == 1 << 31) {
                break;
            }
            mask = mask << 1;
            if ((ba && bb) || (bb && bc) || (bc && ba)) {
                c = mask;
            }
        }
        return result;
    }
};