class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char x : s) {
            if (x == '(' || x == '{' || x == '[') {
                st.push(x);
            } else {
                if (st.empty())
                    return false;

                char a = st.top();
                st.pop();

                if ((x == ')' && a != '(') || (x == '}' && a != '{') ||
                    (x == ']' && a != '[')) {
                    return false;
                }
            }
        }

        return st.empty(); 
    }
};