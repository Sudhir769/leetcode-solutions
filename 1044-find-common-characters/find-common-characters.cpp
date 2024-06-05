class Solution {
public:
    void fill(string & word, vector<int>& freq){
        for(auto ch: word){
            freq[ch - 'a']++;
        }
    }
    vector<string> commonChars(vector<string>& words) {
        int n = words.size();
        vector<string>ans;
        vector<int> freq(26, 0);

        fill(words[0], freq);

        for(int i=1; i<n; i++){
            vector<int>temp(26, 0);
            fill(words[i], temp);

            for(int j=0; j<26; j++){
                freq[j] = min(freq[j], temp[j]);
            }
        }
        for(int i=0; i<26; i++){
            int cnt = freq[i];
            while(cnt--){
                ans.push_back(string(1, i+'a'));
            }
        }
        return ans;
    }
};