class Solution {
public:
    string findLatestTime(string s) {
        int n = s.length();
        for(int i=0; i<n; i++){
            if(s[i] == '?'){
                if(i == 0){
                    s[i] = (s[1] >= '2' and s[1] <= '9') ? '0':'1';
                }else if(i == 1){
                    if(s[0] != '1'){
                        s[i] = '9';
                    }else{
                        s[i] = '1';
                    }
                }else if(i == 3){
                    s[i] = '5';
                }else{
                    s[i] = '9';
                }
            }
        }
        return s;
    }
};