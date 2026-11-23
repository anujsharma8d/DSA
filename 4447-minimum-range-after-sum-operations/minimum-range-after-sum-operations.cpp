class Solution {
public:
    int minRange(int a, int b, int c) {
        int range1 = max({a,b,c})-min({a,b,c});
        int range2 = max({a,b,a+b})-min({a,b,a+b});
        int range3 = max({a,a+c,c})-min({a,a+c,c});
        int range4 = max({b+c,b,c})-min({b+c,b,c});
        return min({range1,range2,range3,range4});
    }
};