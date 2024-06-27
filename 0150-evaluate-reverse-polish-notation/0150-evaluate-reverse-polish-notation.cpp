#include <stdlib.h>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                st.push(a + b);
            } else if (tokens[i] == "-") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                st.push(b - a);
            } else if (tokens[i] == "*") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();  
                st.push(a * b);
            } else if (tokens[i] == "/") {
                long long a = st.top();
                st.pop();
                long long b = st.top();
                st.pop();
                st.push(b / a);
            } else {
                st.push(stoll(tokens[i]));
            }
        }
        
        return st.top();
    }
};