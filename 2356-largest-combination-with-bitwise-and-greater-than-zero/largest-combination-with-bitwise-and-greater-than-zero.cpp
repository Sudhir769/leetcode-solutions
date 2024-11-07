class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int maxi = 0;

        for(int i=0; i<24; i++){
            int curr = 0;
            for(auto num:candidates){
                if(num & (1<<i)){
                    curr++;
                }
            }
            maxi = max(maxi, curr);
        }
        return maxi;
    }
};