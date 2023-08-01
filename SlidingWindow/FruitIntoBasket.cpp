// lc-904 , similar to longest substring with at-most K (2 in this case) characters.

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        int n = fruits.size();
        if(n <= 2) return n;
        int maxFruits = -1;
        int startIndex = 0;
        int count = 0;

        unordered_map<int,int> fruitsFreq; // <fruitNumber,frequency>

        for(int i = 0 ; i< n; i++){
            
            fruitsFreq[fruits[i]]++;

            if(fruitsFreq[fruits[i]] == 1){
                count++; // got a new fruit variety
                while(count > 2){
                   fruitsFreq[fruits[startIndex]]--;
                    if(fruitsFreq[fruits[startIndex]] == 0){
                        count--;
                    }
                    startIndex++;
                }
            }
              maxFruits = max(maxFruits,i-startIndex+1);
        }
      
        return maxFruits;
    }
};
