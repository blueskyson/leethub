class Solution {
public:
    int totalStrength(vector<int>& st) {
        long long MOD = 1000000007;
        const int N = st.size();
        // sum of first k elements
        vector<long long> prefix(N + 1, 0L);
        for (int i = 0; i < N; ++i) {
            prefix[i + 1] = (prefix[i] + st[i]) % MOD;
        }
        // sum of first k prefix
        vector<long long> prefix_sum(N + 2, 0L);
        for (int i = 0; i <= N; ++i) {
            prefix_sum[i + 1] = (prefix_sum[i] + prefix[i]) % MOD;
        }
        
        // for (int i = 0; i < N + 1; i++) {
        //     cout << prefix[i] << " ";
        // }
        // cout << endl;
        // for (int i = 0; i < N + 2; i++) {
        //     cout << prefix_sum[i] << " ";
        // }
        // cout << endl;
        
        // first index on the left < current st
        vector<int> left(N, -1);
        vector<int> stack;
        for (int i = 0; i < N; ++i) {
            while (!stack.empty() && st[stack.back()] >= st[i]) {
                stack.pop_back();
            }
            left[i] = stack.empty() ? -1 : stack.back();
            stack.push_back(i);   
        }
        // for (int i = 0; i < N; i++) {
        //     cout << left[i] << " ";
        // }
        // cout << endl;
        
        // first index on the right <= current st
        vector<int> right(N, N);
        stack.clear();
        for (int i = N - 1; i >= 0; --i) {
            while (!stack.empty() && st[stack.back()] > st[i]) {
                stack.pop_back();
            }
            right[i] = stack.empty() ? N : stack.back();
            stack.push_back(i);
        }
        // for (int i = 0; i < N; i++) {
        //     cout << right[i] << " ";
        // }
        // cout << endl;

        long long res = 0;
        for (int i = 0; i < N; ++i) {
            long long positive_part = (prefix_sum[right[i] + 1] - prefix_sum[i + 1]) * (i - left[i]) % MOD;
            long long negative_part = (prefix_sum[i + 1] - prefix_sum[left[i] + 1]) * (right[i] - i) % MOD;
            long long all_range_sum = (positive_part + 2 * MOD - negative_part) % MOD;
            res = (res + all_range_sum * st[i] % MOD) % MOD;
        }
        return (int) res;
    }
};