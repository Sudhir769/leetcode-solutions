class Solution {
public:
    int findComplement(int num) {
        int i=0;
        int comp = 0;

        while(num){
            if(!(num & 1)){
                comp |= (1 << i);
            }
            num >>= 1;
            i++;
        }
        return comp;
    }
};