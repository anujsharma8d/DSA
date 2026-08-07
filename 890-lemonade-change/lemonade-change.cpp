class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five=0;
        int ten=0;
        int twenty=0;
        if(bills[0]!=5){
            return false;
        }
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                five++;
            }
            if(bills[i]==10){
                ten++;
                five--;
            }
            if(bills[i]==20){
                twenty++;
                if(ten>0){
                    ten--;
                    five--;
                }
                else{
                    five-=3;
                }
            }
            if(five<0 || ten<0){
                return false;
            }
        }
        return true;
    }
};