class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string result = "";

        for(int i=0; i<s.length(); i++){
            if(s[i] == '('){
                st.push(result.length());
            }else if(s[i] == ')'){
                reverse(result.begin() + st.top(), result.end());
                st.pop();
            }else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};