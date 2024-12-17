class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        int n = s.length();

        vector<int> freq(26, 0);
        for(auto ch:s){
            freq[ch - 'a']++;
        }
        
        priority_queue<char> pq;
        for(int i=0; i<26; i++){
            if(freq[i] > 0){
                pq.push(i+'a');
            }
        }

        string result = "";
        while(!pq.empty()){
            auto ch = pq.top();
            pq.pop();

            int fr = min(freq[ch-'a'], repeatLimit);
            result.append(fr, ch);

            freq[ch-'a'] -= fr;

            if(freq[ch-'a'] > 0 and !pq.empty()){
                char nextch = pq.top();
                pq.pop();

                result.push_back(nextch);
                freq[nextch-'a']--;

                if(freq[nextch-'a'] > 0){
                    pq.push(nextch);
                }
                pq.push(ch);
            }
        }
        return result;
    }
};