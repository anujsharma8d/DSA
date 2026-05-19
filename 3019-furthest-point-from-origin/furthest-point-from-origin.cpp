class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int countl=0;
        int countr=0;
        int count=0;
        int n=moves.size();
        for(int i=0;i<n;i++){
            if(moves[i]=='L'){
                countl++;
            }
            else if(moves[i]=='R'){
                countr++;
            }
            else{
                count++;
            }
        }
        if(countl>countr){
            return countl+count-countr;
        }
        return countr+count-countl;
    }
};