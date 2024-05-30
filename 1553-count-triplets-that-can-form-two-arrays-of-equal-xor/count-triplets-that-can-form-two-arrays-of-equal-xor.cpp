class Solution {
public:
    int countTriplets(vector<int>& arr) {
        vector<int>prefix(arr.begin(), arr.end());
        prefix.insert(prefix.begin(), 0);
        int n = prefix.size();

        for(int i=1; i<n; i++){
            prefix[i] ^= prefix[i-1]; 
        }
        int triplet = 0;
        for(int i=0; i<n; i++){
            for(int k=i+1; k<n; k++){
                if(prefix[k] == prefix[i]){
                    triplet += k-i-1;
                }
            }
        }
        return triplet;
    }
};