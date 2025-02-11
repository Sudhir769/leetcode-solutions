class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int m = part.length();

        string result = "";
        for(int i=0; i<n; i++){
            char ch = s[i];

            result.push_back(ch);
            if(result.length() >= m and result.substr(result.length() - m) == part){
                result = result.substr(0, result.length() - m);
            }
        }
        return result;
    }
};