class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int flips = 0;

        int flipCountPast = 0;
        deque<int> dq;

        for(int i=0; i<n; i++){
            if(i >= 3){
                flipCountPast -= dq.front();
                dq.pop_front();
            }

            if(flipCountPast % 2 == nums[i]){
                if(i+3 > n){
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