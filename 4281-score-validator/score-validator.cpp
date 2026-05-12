class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score=0;
        int counter=0;
        int n=events.size();
        for(int i=0;i<n;i++){
            if(events[i]=="1" || events[i]=="2" || events[i]=="3" || events[i]=="4" || events[i]=="0" || events[i]=="6"){
                score+=stoi(events[i]);
            }
            else if(events[i]=="W"){
                counter++;
            }
            else{
                score++;
            }
            if(counter==10){
                break;
            }
        }
        return {score,counter};

    }
};