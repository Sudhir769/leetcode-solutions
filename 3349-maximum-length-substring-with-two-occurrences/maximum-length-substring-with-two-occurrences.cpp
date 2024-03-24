class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<int, int>mp;
        int ans = 0;
        for(int i=0, j=0; i<s.length(); i++){
            mp[s[i]]++;
            while(j<i and mp[s[i]] > 2) mp[s[j++]]--;
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};