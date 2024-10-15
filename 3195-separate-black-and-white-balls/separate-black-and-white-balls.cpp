class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.length();
        int black = 0, white = n-1;
        long long cnt = 0;
        while(black < white){
            if(s[black] == '1' and s[white] == '0'){
                cnt += white - black;
                black++, white--;
            }else if(s[white] == '1'){
                white--;
            }else{
                black++;
            }
        }
        return cnt;
    }
};