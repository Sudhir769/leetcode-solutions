class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        stack<int>st;
        vector<int>index(n, -1);

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                int j = st.top();
                st.pop();

                index[i] = j;
                index[j] = i;
            }
        }

        string result = "";
        int dir = 1;

        for(int i=0; i<n; i+=dir){
            if(s[i] == '(' or s[i] == ')'){
                i = index[i];
                dir = -dir;
            }else{
                result.push_back(s[i]);
            }
        }
        return result;
    }
};