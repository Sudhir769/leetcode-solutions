class Solution {
public:
    int cnt = 0;
    void solve(vector<int> &freq){
        cnt++;

        for(int i=0; i<26; i++){
            if(freq[i] == 0) continue;

            freq[i]--;
            solve(freq);
            freq[i]++;
        }

    }
    int numTilePossibilities(string tiles) {
        vector<int> freq(26, 0);
        for(auto ch:tiles){
            freq[ch-'A']++;
        }

        solve(freq);
        return cnt-1;
    }
};