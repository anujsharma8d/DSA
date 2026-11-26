class Solution {
public:
    bool canAliceWin(int n) {
        bool turn = false; //ALICE
        int i = 0;
        while(true){
            n-=(10-i);
            if(n<0){
                break;
            }
            turn = !turn;
            i++;
        }
        if(turn){
            return true;
            }
        return false;

    }
};