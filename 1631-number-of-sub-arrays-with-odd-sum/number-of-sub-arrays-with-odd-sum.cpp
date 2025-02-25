class Solution {
public:
    int numOfSubarrays(vector<int>& nums) {
        int n = nums.size();
        int M = 1e9+7;

        vector<int> prefix(n, 0);
        prefix[0] = nums[0];

        for(int i=1; i<n; i++){
            prefix[i] = prefix[i-1] + nums[i];
        }

        int cnt = 0;
        int odd = 0, even = 1;

        for(int i=0; i<n; i++){
            if(prefix[i] % 2 == 0){
                cnt = (cnt + odd) % M;
                even++;
            }else{
                cnt = (cnt + even) % M;
                odd++;
            }
        }
        return cnt;
    }
};