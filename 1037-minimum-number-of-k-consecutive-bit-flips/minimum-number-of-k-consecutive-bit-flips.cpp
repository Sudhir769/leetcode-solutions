class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;

        int flipCnt = 0;
        vector<bool> isFlipped(n, 0);

        for(int i=0; i<n; i++){
            if(i >= k and isFlipped[i-k] == true){
                flipCnt--;
            }

            if(flipCnt % 2 == nums[i]){
                if(i+k > n){
                    return -1;
                }

                flipCnt++;
                flips++;
                isFlipped[i] = true;
            }
        }
        return flips;
    }
};