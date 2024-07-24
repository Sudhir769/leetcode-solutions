class Solution {
public:
    string getMapped(string &num, vector<int>& mapping){
        string mappedNum = "";
        for(int i=0; i<num.length(); i++){
            char ch = num[i];
            int intch = ch - '0';
            mappedNum += to_string(mapping[intch]);
        }
        return mappedNum;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();

        vector<pair<int, int>> vec;
        for(int i=0; i<n; i++){
            string numStr = to_string(nums[i]);
            string mappedStr = getMapped(numStr, mapping);

            int mappedNum = stoi(mappedStr);
            vec.push_back({mappedNum, i});
        }
        
        sort(vec.begin(), vec.end());
        vector<int>result;
        for(auto it:vec){
            int originalIndex = it.second;
            result.push_back(nums[originalIndex]);
        }
        return result;
    }
};