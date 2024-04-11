class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        string result = "";

        for(int i=0; i<n; i++){
            while(result.length() > 0 and result.back() > num[i] and k > 0){
                result.pop_back();
                k--;
            }

            if(result.length() > 0 or num[i] != '0'){
                result.push_back(num[i]);
            }
        }

        while(result.length() and k--){
            result.pop_back();
        }

        if(result == "") return "0";
        return result;
    }
};