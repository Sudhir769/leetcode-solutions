class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> cnt(1e6+2, 0);

        for(int i=0; i<n-1; i++){
            for(int j=i+1; j<n; j++){
                int dist = abs(nums[i] - nums[j]);
                cnt[dist]++;
            }
        }
        for(int i=0; i<1e6+1; i++){
            k -= cnt[i];
            if(k <= 0){
                return i;
            }
        }
        return 0;
    }
};