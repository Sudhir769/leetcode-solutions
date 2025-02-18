class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.length();
        string ans = "1";
        string temp = "";

        for(int i=0; i<pattern.size(); i++){
            if(pattern[i] == 'I'){
                ans += (temp + char(i + '2'));
                temp = "";
            }else{  
                temp = char(ans.back()) + temp;
                ans.pop_back();
                ans += char(i+'2'); 
            }
        }
        return ans + temp;
    }
};