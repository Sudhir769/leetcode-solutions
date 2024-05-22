class Solution {
public:
    int n = 0;
    vector<vector<string>>ans;
    bool isPalindrome(int start, int end, string s){
        while(start <= end){
            if(s[start++] != s[end--]){
                return false;
            }
        }
        return true;
    }
    void solve(int i, string s, vector<string> temp){
        if(i == n){
            ans.push_back(temp);
            return;
        }
        for(int j=i; j<n; j++){
            if(isPalindrome(i, j, s)){
                temp.push_back(s.substr(i, j-i+1));
                solve(j+1, s, temp);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        n = s.length();
        solve(0, s, {});
        return ans;
    }
};