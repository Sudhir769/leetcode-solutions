class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();

        int ele = nums[0];
        int cnt = 0;

        for(int i=0; i<n; i++){
            if(nums[i] == ele){
                cnt++;
            }else{
                cnt--;
            }
            if(cnt == 0){
                cnt = 1;
                ele = nums[i];
            }
        }
        return ele;
    }
};