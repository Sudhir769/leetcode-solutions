class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n = words.size();

        unordered_set<string> st;
        for(int i=0; i<n; i++){
            string word = words[i];
            for(int j=0; j<n; j++){
                if(words[j] == word) continue;
                if(words[j].find(word) != string::npos){
                    st.insert(word);
                }
            }
        }
        vector<string> ans(st.begin(), st.end());
        return ans;
    }
};