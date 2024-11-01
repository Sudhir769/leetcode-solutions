class Solution {
public:
    string makeFancyString(string s) {
        int n = s.length();
        string result = "";

        result.push_back(s[0]);
        int cnt = 1;

        for(int i=1; i<n; i++){
            if(s[i] == result.back()){
                if(cnt < 2){
                    result.push_back(s[i]);
                    cnt++;
                }
            }else{
                result.push_back(s[i]);
                cnt = 1;
            }
        }
        return result;
    }
};