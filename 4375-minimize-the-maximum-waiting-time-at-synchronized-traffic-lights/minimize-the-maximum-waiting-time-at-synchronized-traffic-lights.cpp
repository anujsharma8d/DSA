class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        sort(lights.begin(),lights.end());
        int n=arrivalTime.size();
        int last=lights[lights.size()-1];
        int time=0;
        for(int i=0;i<n;i++){
            int r = arrivalTime[i]%period;
            if(r<last){
                time+=0;
            }
            else{
                time=max(period-r,time);
            }
        }
        return time;
    }
};