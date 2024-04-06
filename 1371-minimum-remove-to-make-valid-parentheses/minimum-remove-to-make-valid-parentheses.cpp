class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n = s.length();
        stack<int>st;
        unordered_set<int>index;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                st.push(i);
            }else if(s[i] == ')'){
                if(st.empty()){
                    index.insert(i);
                }else{
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            index.insert(st.top());
            st.pop();
        }
        string result;
        for(int i=0; i<n; i++){
            if(index.find(i) == index.end()){
                result.push_back(s[i]);
            }
        }
        return result;
    }
};