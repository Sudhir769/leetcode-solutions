class Solution {
public:
    int maxDepth(string s) {
        stack<char>st;
        int n = s.length();
        int ans=0, cnt=0;
        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(s[i]);
                cnt++;
                ans = max(ans, cnt);
            }else if(s[i] == ')'){
                st.pop();
                cnt--;
            }
        }
        return ans;
    }
};