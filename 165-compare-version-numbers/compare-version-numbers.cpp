class Solution {
public:
    vector<string> getString(string version){
        stringstream ss(version);

        string token = "";
        vector<string>tokens;
        while(getline(ss, token, '.')){
            tokens.push_back(token);
        }
        return tokens;
    }
    int compareVersion(string version1, string version2) {
        vector<string>v1 = getString(version1);
        vector<string>v2 = getString(version2);

        int n = v1.size(), m = v2.size();
        int i=0;
        int j = max(n, m);
        while(i < j){
            int a = i < n ? stoi(v1[i]) : 0;
            int b = i < m ? stoi(v2[i]) : 0;

            if(a == b){
                i++;
            }else if(a > b){
                return 1;
            }else{
                return -1;
            }
        }
        return 0;
    }
};