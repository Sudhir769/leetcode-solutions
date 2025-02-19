class Solution {
public:
    string ans;
    int cnt = 0;
    void solve(int n, string& temp, int k){
        if(temp.length() == n){
            cnt++;
            if(cnt == k) ans = temp;
            return;
        }

        if(!ans.empty()) return;

        for(char ch='a'; ch<='c'; ch++){
            if(!temp.empty() and temp.back() == ch) continue;

            temp.push_back(ch);
            solve(n, temp, k);
            temp.pop_back();
        }
    }
    string getHappyString(int n, int k) {
        string temp = "";
        solve(n, temp, k);
        return ans;
    }
};