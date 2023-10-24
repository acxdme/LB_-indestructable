// Optimized Sieve of Eratothesis 

class Solution {
public:
    int countPrimes(int n) {
        // sieve of eratothesis
       int res = 0;
       vector<bool> sieve(n,true);
       for(int i = 2 ; i*i <= n ;i++){ // optimization - 2
           if(sieve[i]){
           int f = i * i ; // optimization - 1
            while( f < n){
                sieve[f] = false;
                f += i;
            }
           }
       }
       for ( int i =2 ; i < n ;i++){
           if(sieve[i]) res ++;
       }
       return res;
    }
};
