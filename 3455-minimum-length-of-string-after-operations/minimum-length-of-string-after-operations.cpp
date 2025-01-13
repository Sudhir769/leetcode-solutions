class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        vector<int> freq(26, 0);
        int cnt = 0;
        for(auto ch:s){
            freq[ch- 'a']++;
            if(freq[ch-'a'] >= 3){
                freq[ch-'a'] -= 2;
                cnt += 2;
            }
        }
        return n - cnt;
    }
};