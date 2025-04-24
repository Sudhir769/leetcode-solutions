class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        unordered_set<int> st;
        for(auto num:nums){
            st.insert(num);
        }
        int elements = st.size();

        int result = 0;
        int i=0, j=0;
        unordered_map<int, int> mp;
        while(j < n){
            mp[nums[j]]++;

            while(mp.size() == elements){
                result += (n - j);

                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }
            j++;
        }
        return result;
    }
};