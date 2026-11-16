class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        st.push(asteroids[0]);
        int i=1;
        while(i<n){
            while(!st.empty() && st.top()>0 && asteroids[i]<0 && abs(asteroids[i])>st.top()){
                st.pop();
            }
            if(!st.empty() && asteroids[i]<0 && st.top()==abs(asteroids[i])){
                st.pop();
                i++;
                continue;
            }
            if(st.empty()){
                st.push(asteroids[i]);
            }
            else if(!st.empty() && asteroids[i]>0 && st.top()>0){
                st.push(asteroids[i]);
            }
            else if(!st.empty() && asteroids[i]<0 && st.top()<0){
                st.push(asteroids[i]);
            }
            else if(!st.empty() && asteroids[i]>0 && st.top()<0){
                st.push(asteroids[i]);
            }

            i++;
        }
        int idx = st.size()-1;
        vector<int> ans(st.size(),0);
        while(!st.empty()){
            int x = st.top();
            ans[idx]=x;
            st.pop();
            idx--;
        }
        return ans;
    }
};