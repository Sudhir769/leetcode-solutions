class Solution {
public:
    string compressedString(string word) {
        string result = "";
        int n = word.length();

        int i = 0;
        while(i < n){
            char ch = word[i];
            int cnt = 0;

            while(i < n and cnt < 9 and word[i] == ch){
                cnt++;
                i++;
            }
            result += to_string(cnt) + ch;
        }
        return result;
    }
};