class Solution {
public:
    int tribonacci(int n) {
        int first = 0, second = 1, third = 1;

        if(n<3) return n != 0;

        for(int i=3; i<=n; i++){
            int fourth = first + second + third;
            first = second;
            second = third;
            third = fourth;
        }
        return third;
    }
};