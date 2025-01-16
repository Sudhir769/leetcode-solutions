class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int result = 0;
        unordered_map<long long, long long> mp;

        for(int i=0; i<n; i++){
            mp[nums1[i]] += m;
        }

        for(int j=0; j<m; j++) {
            mp[nums2[j]] += n;
        }

        for(auto it:mp){
            if(it.second % 2){
                result ^= it.first;
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