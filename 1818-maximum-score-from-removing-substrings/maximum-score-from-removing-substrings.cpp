class Solution {
public:
    string solve(string s, string substr){
        int n = s.length();
        stack<char>st;

        for(auto ch:s){
            if(!st.empty() and ch == substr[1] and st.top() == substr[0]){
                st.pop();
            }else{
                st.push(ch);
            }
        }

        string result = "";
        while(!st.empty()){
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;

        string maxString = (x > y) ? "ab":"ba"; 
        string minString = (x < y) ? "ab":"ba"; 

        string temp1 = solve(s, maxString);
        int l = temp1.length();

        score += ((n-l)/2) * max(x, y);

        string temp2 = solve(temp1, minString);
        int l2 = temp2.length();

        score +=  ((l-l2)/2) * min(x, y);

        return score;
    }
};