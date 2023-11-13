class Solution {
public:
    int climbStairs(int n) {
        if(n == 1) // base case
         return 1;
        if( n == 2) // base case
        return 2;

        return climbStairs(n-1) + climbStairs(n-2);
    }
};
