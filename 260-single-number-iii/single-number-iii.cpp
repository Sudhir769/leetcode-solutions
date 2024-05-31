class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        long result = 0;
        for(int i=0; i<n; i++){
            result ^= nums[i];
        }
        long  rightbit = (result & result-1) ^ result;
        int b1=0, b2=0;
        for(int i=0; i<n; i++){
            if(nums[i] & rightbit){
                b1 ^= nums[i];
            }else{
                b2 ^= nums[i];
            }
        }
        return {b1, b2};
    }
};