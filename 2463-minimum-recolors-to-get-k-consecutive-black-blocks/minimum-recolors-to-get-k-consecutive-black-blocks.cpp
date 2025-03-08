class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int maxi = k;
        
        int white = 0;
        for(int j=0, i=0; j<n; j++){
            if(blocks[j] == 'W'){
                white++;
            }
            if(j-i+1 == k){
                maxi = min(maxi, white);
                if(blocks[i] == 'W'){
                    white--;
                }
                i++;
            }
        }
        return maxi;
    }
};