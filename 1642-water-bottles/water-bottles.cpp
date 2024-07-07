class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int drink = 0;
        while(numBottles >= numExchange){
            drink += numExchange;
            numBottles -= numExchange;
            numBottles += 1;
        }
        return drink + numBottles;
    }
};