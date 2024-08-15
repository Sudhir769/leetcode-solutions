class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;

        for(auto bill: bills){
            if(bill == 5){
                five++;

            }else if(bill == 10){
                ten++;
                if(five > 0){
                    five--;
                }else{
                    return false;
                }
            }else{
                if(ten >= 1 and five >= 1){
                    five--, ten--;
                }else if(five >= 3){
                    five -= 3;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};