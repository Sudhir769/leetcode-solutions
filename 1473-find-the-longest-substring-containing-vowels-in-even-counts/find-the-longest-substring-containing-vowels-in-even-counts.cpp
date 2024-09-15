class Solution {
public:
    unordered_set<char> st = {'a', 'e', 'i', 'o', 'u'};
    bool isVowel(char ch){
        return st.count(ch);
    }
    int findTheLongestSubstring(string s) {
        int n = s.length();

        unordered_map<int, int> mp;
        int mask = 0;
        int result = 0;

        mp[mask] = -1;

        for(int i=0; i<n; i++){
            // if(s[i] == 'a'){
            //     mask = (mask ^ (1 << 0));
            // }else if(s[i] == 'e'){
            //     mask = (mask ^ (1 << 1));
            // }else if(s[i] == 'i'){
            //     mask = (mask ^ (1 << 2));
            // }else if(s[i] == 'o'){
            //     mask = (mask ^ (1 << 3));
            // }else if(s[i] == 'u'){
            //     mask = (mask ^ (1 << 4));
            // }
            
            if(isVowel(s[i]))
                mask = (mask ^ (1 << (s[i] - 'a')));

            if(mp.find(mask) != mp.end()){
                result = max(result, i - mp[mask]);
            }else{
                mp[mask] = i;
            }
        }
        return result;
    }
};