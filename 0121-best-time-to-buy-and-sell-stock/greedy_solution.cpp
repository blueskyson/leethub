class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1)
            return 0;
        int maxVal = INT32_MIN;
        int buyIdx = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - prices[buyIdx] > maxVal) {
                maxVal = prices[i] - prices[buyIdx];
            }
            if (prices[i] < prices[buyIdx]) {
                buyIdx = i;
            }
        }
        return maxVal > 0 ? maxVal : 0;
    }
};
