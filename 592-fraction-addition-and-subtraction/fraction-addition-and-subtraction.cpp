class Solution {
public:
    string fractionAddition(string exp) {
        int n = exp.length();

        int num = 0, deno = 1;
        int i=0;
        while(i < n){
            int currNum = 0;
            int currDeno = 0;

            bool isNeg = (exp[i] == '-');
            if(exp[i] == '-' or exp[i] == '+') i++;

            while(i < n and isdigit(exp[i])){
                int val = exp[i] - '0';
                currNum = currNum * 10 + val;
                i++;
            }
            i++;

            if(isNeg) currNum *= -1;

            while(i < n and isdigit(exp[i])){
                int val = exp[i] - '0';
                currDeno = currDeno * 10 + val;
                i++;
            }

            num = (num * currDeno + deno * currNum);
            deno = deno * currDeno;
        }
        int gcd = abs(__gcd(num, deno));
        num /= gcd;
        deno /= gcd;

        return to_string(num) + "/" + to_string(deno);
    }
};