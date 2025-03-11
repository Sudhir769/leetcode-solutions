class Solution {
public:
    bool check(vector<int> &freq){
        return freq[0] > 0 and freq[1] > 0 and freq[2] > 0;
    }
    int numberOfSubstrings(string s) {
        int n = s.length();
        int cnt = 0;
        vector<int> freq(3, 0);
        for(int i=0, j=0; j<n; j++){
            char ch = s[j];
            freq[ch - 'a']++;
            while(check(freq)){
                cnt += 1 + (n-j-1);
                freq[s[i] - 'a']--;
                i++;
            }
        }
        return cnt;
    }
};