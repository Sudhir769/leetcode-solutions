class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;

        for (char ch : expression) {
            if (ch == ')') {
                vector<char> subExpr;
                while (st.top() != '(') {
                    subExpr.push_back(st.top());
                    st.pop();
                }
                st.pop(); 

                char op = st.top();
                st.pop(); 
                if (op == '!') {
                    st.push(subExpr[0] == 't' ? 'f' : 't');
                } else if (op == '&') {
                    char result = 't';
                    for (char e : subExpr) {
                        if (e == 'f') {
                            result = 'f';
                            break;
                        }
                    }
                    st.push(result);
                } else if (op == '|') {
                    char result = 'f';
                    for (char e : subExpr) {
                        if (e == 't') {
                            result = 't';
                            break;
                        }
                    }
                    st.push(result);
                }
            } else if (ch != ',') {
                st.push(ch);
            }
        }
        
        return st.top() == 't';
    }
};