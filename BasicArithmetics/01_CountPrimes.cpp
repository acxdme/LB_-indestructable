// TC : O(n*log(log N))
// SC : O(N)
// approach : Sieve of Eratosthenes

class Solution {
public:
    int countPrimes(int n) {
        // sieve of eratothesis
       int res = 0;
       vector<bool> sieve(n,true);
       for(int i = 2 ; i < n ;i++){
           if(sieve[i]){
            int f = 2;
            res++;
            while( i*f < n){
                sieve[i*f] = false;
                f++;
            }
           }
       }
       return res;
    }
};
