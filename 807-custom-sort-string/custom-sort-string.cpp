class Solution {
public:
    string customSortString(string order, string s) {
        vector<int>mp(26, -1);

        for(int i=0; i<order.size(); i++){
            mp[order[i]-'a'] = i;
        }

        auto lambda = [&mp](char& ch1, char& ch2){
            return mp[ch1-'a'] < mp[ch2 -'a'];
        };

        sort(s.begin(), s.end(), lambda);
        return s;
    }
};