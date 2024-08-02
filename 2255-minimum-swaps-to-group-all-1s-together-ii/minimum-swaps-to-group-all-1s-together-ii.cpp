class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        int i=0, j=0;
        int ones = count(nums.begin(), nums.end(), 1);

        int currCnt = 0, maxCnt = 0;
        while(j < 2*n){
            if(nums[j%n] == 1){
                currCnt++;
            }

            if(j-i+1 > ones){
                currCnt -= nums[i%n];
                i++;
            }
            maxCnt = max(maxCnt, currCnt);
            j++;
        }
        return ones - maxCnt;
    }
};