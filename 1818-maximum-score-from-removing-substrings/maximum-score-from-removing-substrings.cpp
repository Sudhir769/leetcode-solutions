class Solution {
public:
    string solve(string s, string substr){
        int n = s.length();

        int i=0, j=0;
        for(j=0; j<n; j++){
            s[i] = s[j];
            i++;

            if(i>1) {
                if(s[i-2] == substr[0] and s[i-1] == substr[1]){
                    i -= 2;
                }
            }
        }
        s.erase(s.begin()+i, s.end());
        return s;
        
    }
    int maximumGain(string s, int x, int y) {
        int n = s.length();
        int score = 0;

        string maxString = (x > y) ? "ab":"ba"; 
        string minString = (x < y) ? "ab":"ba"; 

        string temp1 = solve(s, maxString);
        int l = temp1.length();

        score += ((n-l)/2) * max(x, y);

        string temp2 = solve(temp1, minString);
        int l2 = temp2.length();

        score +=  ((l-l2)/2) * min(x, y);

        return score;
    }
};