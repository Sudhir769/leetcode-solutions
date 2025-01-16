class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int result = 0;
        
        if(n % 2 != 0){
            for (auto num:nums2){
                result ^= num;
            }
        }
        if(m % 2 != 0){
            for (auto num:nums1){
                result ^= num;
            }
        }

        return result;
    }
};
// 0 0 1  
// 0 1 0
// 0 1 1

// 0 1 1
// 1 0 0
// 1 1 1
// 0 1 1
// 1 0 0 


// 1 0 1 0
// 0 0 1 0
// 0 1 0 1
// 0 0 0 0