class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string token = "";

        int i=0;
        while(ss >> token){
            i++;
            if(token.find(searchWord) != string::npos){
                int j=0;
                bool flag = true;
                while(j < searchWord.length() and j < token.length()){
                    if(token[j] != searchWord[j]){
                        flag = false;
                    }
                    j++;
                }
                if(flag){
                    return i;
                }
            }
        }
        return -1;
    }
};