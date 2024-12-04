class Solution {
public:
    char nextChar(char ch) {
        return (ch - 'a' + 1) % 26 + 'a'; 
    }

    char previousChar(char ch) {
        return (ch - 'a' - 1 + 26) % 26 + 'a'; 
    }

    bool canMakeSubsequence(string str1, string str2) {
        int n = str1.length();
        int m = str2.length();

        int i=0, j=0;

        while(i<n and j<m){
            if(str1[i] == str2[j]){
                i++, j++;
                continue;
            }
            if(nextChar(str1[i]) == str2[j]){
                i++, j++;
                continue;
            }
            // if(previousChar(str1[i]) == str2[j]){
            //     i++, j++;
            //     continue;
            // }
            i++;
        }        
        return j>=m;
    }
};