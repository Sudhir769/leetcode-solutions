class Solution {
public:
    int pivotInteger(int n) {
        int total = n*(n+1)/2;

        int pivot = sqrt(total);

        return (pivot*pivot == total)? pivot:-1;
    }
};