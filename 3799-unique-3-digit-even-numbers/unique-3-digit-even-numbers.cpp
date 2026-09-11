class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10,0);
        for(int x:digits){
            freq[x]++;
        }
        int ans=0;
        for(int i=100;i<=999;i++){
            if(i%2!=0){
                continue;
            }
            int a=i/100;
            int b=(i/10)%10;
            int c=i%10;

            bool possible=true;

            vector<int> need(10,0);
            need[a]++;
            need[b]++;
            need[c]++;

            for(int j=0;j<=9;j++){
                if(need[j]>freq[j]){
                    possible=false;
                    break;
                }
            }

            if (possible){
                ans++;
            }
        }
        return ans;
    }
};