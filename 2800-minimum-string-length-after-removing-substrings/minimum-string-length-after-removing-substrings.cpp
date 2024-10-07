class Solution {
public:

    int minLength(string s) {
        int n = s.length();
        stack<char> st;

        for(int i=0; i<n; i++){
            char ch = s[i];

            if(ch == 'B' or ch == 'D'){
                if(!st.empty() and ((ch == 'B' and st.top() == 'A') or (ch == 'D' and st.top() == 'C'))){
                    st.pop();
                }else{
                    st.push(ch);
                }
                continue;
            }
            st.push(ch);
        }
        return st.size();
    }
};