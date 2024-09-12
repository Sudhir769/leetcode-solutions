class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st;
        for(auto ch:allowed){
            st.insert(ch);
        }
        int cnt = 0;
        for(string word:words){
            for(char ch:word){
                if(st.find(ch) == st.end()){
                    cnt--;
                    break;
                }
            }
            cnt++;
        }
        return cnt;
    }
};