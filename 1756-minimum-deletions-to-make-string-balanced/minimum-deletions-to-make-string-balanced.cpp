class Solution {
public:
    int minimumDeletions(string s) {
        stack<char> st;
        int deletions = 0;
        for(auto ch:s){
            if(!st.empty() and st.top() == 'b' and ch == 'a'){
                st.pop();
                deletions++;
            }else{
                st.push(ch);
            }
        }
        return deletions;
    }
};