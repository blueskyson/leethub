class Solution {
public:
    int max;
    int integerBreak(int n) {
        int maxProduct = INT32_MIN;
        int num = 1;
        int half = (n + 1) / 2;
        while (num <= half) {
            int remain = n;
            int product = 1;
            while (remain > num * 2) {
                product *= num;
                remain -= num;
            }
            
            if (remain == num * 2) {
                product = product * num * num;
            } else {
                int a = remain != n ? product * remain : INT32_MIN;
                int b = product * num * (remain - num);
                product = a > b ? a : b;
            }
            
            if (product > maxProduct) {
                maxProduct = product;
            } else {
                return maxProduct;
            }
            
            num++;
        }
        
        return maxProduct;
    }
};