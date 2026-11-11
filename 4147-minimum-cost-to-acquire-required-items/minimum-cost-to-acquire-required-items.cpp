class Solution {
public:
    typedef long long ll;
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll one = 1LL*cost1*need1;
        ll two = 1LL*cost2*need2;
        ll case1 = one+two;
        ll case2 = 1LL*max(need1,need2)*costBoth;
        ll case3 = 1LL*min(need1,need2)*costBoth;
        if(need1>need2){
            case3+=1LL*(need1-need2)*cost1;
        }
        else{
            case3+=1LL*(need2-need1)*cost2;
        }
        // cout<<case1<<endl;
        // cout<<case2<<endl;
        // cout<<case3<<endl;
        return min({case1,case2,case3});
    }
};