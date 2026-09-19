class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        int x,y;
        if(x2>=xCenter && x1<=xCenter){
            x=xCenter;
        }
        else if(x1>xCenter){
            x=x1;
        }
        else{
            x=x2;
        }
        if(y2>=yCenter && y1<=yCenter){
            y=yCenter;
        }
        else if(y1>yCenter){
            y=y1;
        }
        else{
            y=y2;
        }
        float dist = ((x-xCenter)*(x-xCenter)+(y-yCenter)*(y-yCenter));
        if(dist>radius*radius){
            return false;
        }
        return true;
    }
};