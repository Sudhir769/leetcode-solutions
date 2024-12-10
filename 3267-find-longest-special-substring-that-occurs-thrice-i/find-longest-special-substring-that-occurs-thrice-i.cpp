class Solution {
public:
    int maximumLength(string s) {
        int n = s.length();
        map<pair<int, int>, int> mp;

        for(int i=0; i<n; i++){
            char ch = s[i];
            int l=0;

            for(int j=i; j<n; j++){
                if(ch == s[j]){
                    l++;
                    mp[{ch, l}]++;
                }else{
                    break;
                }
            }
        }

        int result = 0;
        for(auto it:mp){
            int length = it.first.second;
            int freq = it.second;

            if(freq >= 3){
                result = max(result, length);
            }
        }
        return result == 0 ? -1:result;
    }
};