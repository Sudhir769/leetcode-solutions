class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st;
        for(auto it:arr1){
            while(!st.count(it) and it > 0){
                st.insert(it);
                it /= 10;
            }
        }

        int result = 0;
        for(auto it: arr2){
            while(!st.count(it) and it > 0){
                it /= 10;
            }

            if(it > 0){
                result = max(result, static_cast<int>(log10(it)+1));
            }
        }
        return result;
    }
};