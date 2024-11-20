class Solution {
public:
    int takeCharacters(string s, int k) {
        int n = s.size();
        vector<int> freq(3, 0);

        for(auto ch:s){
            freq[ch-'a']++;
        }

        if(*min_element(freq.begin(), freq.end()) < k){
            return -1;
        }

        int res = INT_MAX;
        int l = 0;
        for(int r=0; r<n; r++){
            freq[s[r] - 'a']--;

            while(*min_element(freq.begin(), freq.end()) < k){
                freq[s[l]-'a']++;
                l++;
            }
            res = min(res, n-(r-l+1));
        }
        return res;
    }
};