class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1) {
            return x;
        }
        long long int left = 1, right = x;
        while (right > left) {
            long long int mid = left + (right - left) / 2;
            long long int prod = mid * mid;
            cout << left << " " << mid << " "<< right << endl;
            if (prod > x) {
                right = mid - 1;
            } else if (prod < x) {
                left = mid + 1;
            } else {
                return mid;
            }
        }
        
        if (left * left > x) {
            return left - 1;
        }
        return left;
    }
};