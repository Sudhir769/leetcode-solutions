class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        for(int i=0; i<n; i++){
            ans = ans^nums[i];
        }
        int cnt = 0;
        for(int i=0; i<32; i++){
            if((ans & 1) != (k & 1)){
                cnt++;
            }
            ans >>= 1;
            k >>= 1; 
        }
        return cnt;
    }
};