class Solution {
public:
    int minSteps(int n) {
        if(n == 0 or n == 1) return 0;
        if(n == 2)  return 2;

        vector<int> t(n+1, 0);
        t[0] = t[1] = 0;
        t[2] = 2;

        for(int i=3; i<=n; i++){
            int factor = i/2;
            while(factor >= 1){
                if(i % factor == 0){
                    int steps = t[factor];
                    int copy = 1;
                    int paste = (i / factor) - 1;

                    t[i] = steps + copy + paste;
                    break;
                }else{
                    factor--;
                }
            }
        } 
        return t[n];
    }
};