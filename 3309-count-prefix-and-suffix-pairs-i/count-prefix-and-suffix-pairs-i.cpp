class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;

        for(int j=0; j<n; j++){
            string s1 = words[j];
            int l1 = s1.length();

            for(int i=j+1; i<n; i++){
                string s2 = words[i];
                int l2 = s2.length();

                if(l1 > l2) continue;

                if(s2.substr(0, l1) == s1 and s2.substr(l2-l1, l1) == s1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};