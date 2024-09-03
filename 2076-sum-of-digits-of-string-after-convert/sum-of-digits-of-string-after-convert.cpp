class Solution {
public:
    int getLucky(string s, int k) {
        string num = "";
        for(auto ch:s){
            int charInt  = ch - 'a' + 1;
            num += to_string(charInt);
        }
        int sum = 0;
        while(k--){
            sum = 0;
            for(char ch:num){
                sum += ch - '0';
            }
            num = to_string(sum);
        }
        return sum;
    }
};