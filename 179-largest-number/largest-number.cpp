class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto lambda = [](int &n1, int &n2){
            string s1 = to_string(n1);
            string s2 = to_string(n2);

            return s1+s2 > s2+s1;
        };

        sort(nums.begin(), nums.end(), lambda);

        if(nums[0] == 0)  return "0";

        string result = "";
        for(auto it:nums){
            result += to_string(it);
        }
        return result;
    }
};