class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int mask = 0;
        for(auto ch:allowed){
            mask |= (1 << (ch - 'a'));
        }
        int cnt = 0;
        for(string word:words){
            for(char ch:word){
                if(((mask >> (ch - 'a')) & 1) == 0){
                    cnt--;
                    break;
                }
            }
            cnt++;
        }
        return cnt;
    }
};