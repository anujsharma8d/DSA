class Solution {
public:
    int maxDistance(string moves) {
        int distx=0;
        int disty=0;
        int n=moves.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(moves[i]=='U'){
                disty+=1;
            }
            if(moves[i]=='D'){
                disty-=1;
            }
            if(moves[i]=='R'){
                distx+=1;
            }
            if(moves[i]=='L'){
                distx-=1;
            }
            if(moves[i]=='_'){
                count++;
            }
        }
        return abs(distx)+abs(disty)+count;
    }
};