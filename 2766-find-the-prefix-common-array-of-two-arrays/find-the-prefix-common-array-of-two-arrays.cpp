class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        vector<int> result(n, 0);
        unordered_map<int, int> mp;

        int cnt = 0;
        for(int i=0; i<n; i++){
            mp[A[i]]++;
            mp[B[i]]++;
            
            if(mp[A[i]] == 2){
                cnt++;
                mp.erase(A[i]);
            }

            if(mp[B[i]] == 2){
                cnt++;
                mp.erase(B[i]);
            }

            result[i] = cnt;
        }
        return result;
    }
};