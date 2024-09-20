class Solution {
public:
    void solve(vector<int> &lps, string &a){
        int i=0, j=1;

        while(j < a.length()){
            if(a[i] == a[j]){
                i++;
                lps[j] = i;
                j++;
            }else{
                if(i==0){
                    j++;
                }else{
                    i = lps[i-1];
                }
            }
        }
    }
    string shortestPalindrome(string s) {
        string t = s;
        reverse(t.begin(), t.end());
        string a = s + '#' + t;
        int n = a.length();

        vector<int> lps(n, 0);

        solve(lps, a);

        int len = lps[a.length()-1];
        string temp = s.substr(len);
        reverse(temp.begin(), temp.end());
        return temp+s;
    }
};