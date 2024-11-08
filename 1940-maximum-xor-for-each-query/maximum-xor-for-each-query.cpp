class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        int XOR = 0;

        for(auto num:nums){
            XOR ^= num;
        }

        int mask = (1 << maximumBit) - 1;
        vector<int> result(n, 0);
        for(int i=0; i<n; i++){
            int k = (XOR ^ mask);
            result[i] = k;

            XOR ^= nums[n-i-1];
        }
        return result;
    }
};