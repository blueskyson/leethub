class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> minCost(cost.size(), 0);
        minCost[0] = cost[0];
        minCost[1] = cost[1];
        for (int i = 2; i < minCost.size(); i++) {
            minCost[i] = min(minCost[i - 1], minCost[i - 2]) + cost[i];
        }
        
        return min(minCost[minCost.size() - 1], minCost[minCost.size() - 2]);
    }
};