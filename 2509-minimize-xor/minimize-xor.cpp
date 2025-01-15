class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int setBitsCnts = __builtin_popcount(num2);
        cout<<setBitsCnts;
        int temp = pow(2, setBitsCnts)-1;
        int ans = 0;
        for(int i=31; i>=0 and setBitsCnts>0; i--){
            if((1 << i) & num1){
                ans = ans | (1 << i);
                setBitsCnts--;
            }
        }
        for(int i=0; i<32 and setBitsCnts>0; i++){
            if(((1 << i) & ans) == 0){
                ans = ans | (1 << i);
                setBitsCnts--;
            }
        }

        return max(ans, temp);
    }



};
// 1 0 0 0 0 0 1
// 1 0 0 0 0 1 1

// 1 0 1 0 1 0 0


// 1
// 
// 1 1 0 0