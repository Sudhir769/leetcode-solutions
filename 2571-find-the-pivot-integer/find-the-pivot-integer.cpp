class Solution {
public:
    int pivotInteger(int n) {
        int lsum = 1, rsum = n;
        int i = 1, j = n;
        while(i < j){
            if(lsum < rsum){
                i++;
                lsum += i;
            }else{
                j--;
                rsum += j;
            }
        }
        return (lsum == rsum)? i: -1;
    }
};