class Solution {
public:
    bool isVovel(char &c) {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    long long countOfSubstrings(string word, int k) {
        int n = word.length();
        unordered_map<char, int> mp;

        vector<int> nextCons(n);
        int lastConsIndex = n;

        for(int i=n-1; i>=0; i--){
            nextCons[i] = lastConsIndex;
            if(!isVovel(word[i])){
                lastConsIndex = i;
            }
        }
        int i=0, j=0;
        long long count = 0;
        int cons = 0;
        while(j < n){
            char ch = word[j];
            if(isVovel(ch)){
                mp[ch]++;
            }else{
                cons++;
            }

            while(cons > k){
                char ch = word[i];
                if(isVovel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }else{
                    cons--;
                }
                i++;
            }

            while(mp.size() == 5 and cons == k){
                int idx = nextCons[j];
                count += idx - j;
                char ch = word[i];
                if(isVovel(ch)){
                    mp[ch]--;
                    if(mp[ch] == 0){
                        mp.erase(ch);
                    }
                }else{
                    cons--;
                }
                i++;
            }
            j++;
        }
        return count;
    }
};