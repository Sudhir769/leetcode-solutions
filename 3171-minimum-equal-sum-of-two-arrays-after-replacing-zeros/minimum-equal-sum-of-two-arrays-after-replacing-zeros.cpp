class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int zeroes1=0, zeroes2 = 0;
        long long currSum1 = 0, currSum2 = 0;
        for(int &num : nums1) {
            currSum1 += num;
            if(num == 0) zeroes1++;
        }
        for(int &num : nums2) {
            currSum2 += num;
            if(num == 0) zeroes2++;
        }
        if(zeroes1 == 0 && zeroes2 == 0) {
            return currSum1 == currSum2? currSum1 : -1;
        }
        if(zeroes2 == 0) {
            return currSum1 + zeroes1 <= currSum2? currSum2 : -1; 
        }
        else if(zeroes1 == 0) {
            return currSum2 + zeroes2 <= currSum1? currSum1 : -1;
        }
        else {
            return max(currSum1 + zeroes1, currSum2 + zeroes2);
        }
    }
};