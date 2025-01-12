class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.length();
        if(n % 2) return false;

        stack<int> open, openClose;

        for(int i=0; i<n; i++){
            if(locked[i] == '0'){
                openClose.push(i);
            }else if(s[i] == '('){
                open.push(i);
            }else if(s[i] == ')'){
                if(!open.empty()){
                    open.pop();
                }else if(!openClose.empty()){
                    openClose.pop();
                }else{
                    return false;
                }
            }
        }

        while(!open.empty() and !openClose.empty() and open.top() < openClose.top()){
            open.pop();
            openClose.pop();
        }

        return open.empty();
    }
};