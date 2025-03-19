class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        int flips = 0;

        int flipCountPast = 0;
        deque<int> dq;

        for(int i=0; i<n; i++){
            if(i >= k){
                flipCountPast -= dq.front();
                dq.pop_front();
            }

            if(flipCountPast % 2 == nums[i]){
                if(i+k > n){
                    return -1;
                }
                flipCountPast++;
                flips++;
                dq.push_back(1);
            }else{
                dq.push_back(0);
            }
        }
        return flips;
    }
};