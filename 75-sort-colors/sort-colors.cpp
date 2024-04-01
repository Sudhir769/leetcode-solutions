class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3, 0);
        int n = nums.size();

        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                count[0]++;
            }else if(nums[i] == 1){
                count[1]++;
            }else{
                count[2]++;
            }
        }
        int k = 0;
        while(count[0]--) nums[k++] = 0;
        while(count[1]--) nums[k++] = 1;
        while(count[2]--) nums[k++] = 2;
        
        return;
    }
};