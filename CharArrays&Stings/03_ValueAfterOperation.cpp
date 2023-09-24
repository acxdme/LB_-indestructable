// tc : O(N)
// sc : O(1)
// lc-2011

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int res = 0 ;
        int n = operations.size();
        for( int i = 0  ; i < n ;i++ ){
            string word = operations[i];
            if(word ==  "--X"){
                res--;
            }
            else if(word == "X--"){
                res--;
            }
            else if (word == "X++"){
                res++;
            }
            else if (word =="++X"){
                res ++;
            }
            else{
                res += 0;
            }

        }

        return res;
    }
};
