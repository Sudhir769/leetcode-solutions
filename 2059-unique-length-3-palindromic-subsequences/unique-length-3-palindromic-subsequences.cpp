class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();

        unordered_set<char> letters;
        for(int i=0; i<n; i++){
            letters.insert(s[i]);
        }

        int result = 0;
        for(auto letter:letters){
            int left = -1, right = -1;

            for(int i=0; i<n; i++){
                if(s[i] == letter){
                    if(left == -1){
                        left = i;
                    }
                    right = i;
                }
            }
            unordered_set<char> st;
            for(int mid = left+1; mid<right; mid++){
                st.insert(s[mid]);
            }
            result += st.size();
        }
        return result;
    }
};