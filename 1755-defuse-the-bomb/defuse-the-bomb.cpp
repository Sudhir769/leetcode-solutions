class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);

        if(k == 0)  return result;

        int i=-1, j=-1;
        if(k > 0){
            i=1, j=k;
        }else{
            i = n - abs(k);
            j = n - 1;
        }

        int windowSum = 0;
        for(int p=i; p<=j; p++){
            windowSum += code[p];
        }
        for(int k=0; k<n; k++){
            result[k] = windowSum;

            windowSum -= code[i % n];
            i++;

            windowSum += code[(j+1)%n];
            j++;
        }
        return result;
    }
};