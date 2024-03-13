class Solution {
public:
    int pivotInteger(int n) {
        int left = 1, right = n;
        int total = n*(n+1)/2;

        while(left <= right){
            int pivot = left + (right - left)/2;

            if(pivot*pivot == total){
                return pivot;
            }else if(pivot*pivot > total){
                right = pivot - 1;
            }else{
                left = pivot + 1;
            }
        }
        return -1;
    }
};