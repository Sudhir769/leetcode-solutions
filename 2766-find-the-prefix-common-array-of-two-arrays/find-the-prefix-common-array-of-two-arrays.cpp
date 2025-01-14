class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n, 0);
        unordered_map<int, int> mp;

        for(int i=0; i<n; i++){
            mp[B[i]]++;
            int cnt = 0;
            for(int j=0; j<=i; j++){
                if(mp.find(A[j]) != mp.end()){
                    cnt++;
                }
            }
            result[i] = cnt;
        }
        return result;
    }
};