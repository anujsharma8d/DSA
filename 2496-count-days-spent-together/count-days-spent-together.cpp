class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int ans = 0;
        int md[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int aliceArriveMonth = arriveAlice[1]-'0';
        if(arriveAlice[0]=='1'){
            aliceArriveMonth += 10; 
        }
        int aliceLeaveMonth = leaveAlice[1]-'0';
        if(leaveAlice[0]=='1'){
            aliceLeaveMonth += 10; 
        }
        int bobArriveMonth = arriveBob[1]-'0';
        if(arriveBob[0]=='1'){
            bobArriveMonth += 10; 
        }
        int bobLeaveMonth = leaveBob[1]-'0';
        if(leaveBob[0]=='1'){
            bobLeaveMonth += 10; 
        }
        int aliceArriveDate = arriveAlice[4]-'0';
        if(arriveAlice[3]=='1' || arriveAlice[3]=='2' || arriveAlice[3]=='3'){
            aliceArriveDate += (arriveAlice[3]-'0')*10; 
        }
        int aliceLeaveDate = leaveAlice[4]-'0';
        if(leaveAlice[3]=='1' || leaveAlice[3]=='2' || leaveAlice[3]=='3'){
            aliceLeaveDate += (leaveAlice[3]-'0')*10; 
        }
        int bobArriveDate = arriveBob[4]-'0';
        if(arriveBob[3]=='1' || arriveBob[3]=='2' || arriveBob[3]=='3'){
            bobArriveDate += (arriveBob[3]-'0')*10; 
        }
        int bobLeaveDate = leaveBob[4]-'0';
        if(leaveBob[3]=='1' || leaveBob[3]=='2' || leaveBob[3]=='3'){
            bobLeaveDate += (leaveBob[3]-'0')*10; 
        }
        cout<<aliceArriveMonth<<"/"<<aliceArriveDate<<endl;
        cout<<aliceLeaveMonth<<"/"<<aliceLeaveDate<<endl;
        cout<<bobArriveMonth<<"/"<<bobArriveDate<<endl;
        cout<<bobLeaveMonth<<"/"<<bobLeaveDate<<endl;
        int date1 = 0;
        int date2 = 0;
        int month1 = 0;
        int month2 = 0;
        if(aliceArriveMonth > bobArriveMonth){
            month1 = aliceArriveMonth;
            date1 = aliceArriveDate;
        }
        else if(aliceArriveMonth < bobArriveMonth){
            month1 = bobArriveMonth;
            date1 = bobArriveDate;
        }
        else{
            month1 = aliceArriveMonth;
            date1 = max(aliceArriveDate, bobArriveDate);
        }

        if(aliceLeaveMonth < bobLeaveMonth){
            month2 = aliceLeaveMonth;
            date2 = aliceLeaveDate;
        }
        else if(aliceLeaveMonth > bobLeaveMonth){
            month2 = bobLeaveMonth;
            date2 = bobLeaveDate;
        }
        else{
            month2 = aliceLeaveMonth;
            date2 = min(aliceLeaveDate, bobLeaveDate);
        }
        cout<<"date1: "<<date1<<endl;
        cout<<"date2: "<<date2<<endl;
        cout<<"month1: "<<month1<<endl;
        cout<<"month2: "<<month2<<endl;
        int diff = month2-month1;
        if(diff<0){
            return 0;
        }
        else{
            if(diff==0){
                int ans = date2-date1;
                if(ans<0){
                    return 0;
                }
                else{
                    return ans+1;
                }
            }
            else{
                int sum=0;
                sum += md[month1-1]-date1+1;
                for(int i=month1;i<month2-1;i++){
                    sum+=md[i];
                }
                sum += date2;
                return sum;
            }
        }
        
    }
};