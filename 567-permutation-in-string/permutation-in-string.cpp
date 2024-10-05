class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        sort(s1.begin(), s1.end());

        for(int i=0; i<m; i++){
            string substr = s2.substr(i, n);
            sort(substr.begin(), substr.end());

            if(s1 == substr)return true;
        }
        return false;
    }
};