class Solution {
public:
    int longestPalindrome(string s) {
        int n = s.length();
        unordered_map<char, int>mp;
        
        for(int i=0; i<n; i++){
            mp[s[i]]++;
        }
        int ans = 0, flag = 0;
        for(auto it:mp){
            if(it.second == 1) flag = true;
            if(it.second % 2 == 0){
                ans += (it.second);
            }else{
                flag = 1;
                ans +=  (it.second - 1);
            }
        }
        return ans + flag;
    }
};