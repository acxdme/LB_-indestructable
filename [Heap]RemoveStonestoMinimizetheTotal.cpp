/*
  Time complexity : O(n + k*logn)
  Space complexity : O(n)
*/

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        // insert piles into max heap
         for(int i =0 ;i< piles.size();i++){
             pq.push(piles[i]);
         }

        // remove top from heap , apply Kth operation and insert back into max heap
        while(k--){
            int tp = pq.top();
            pq.pop();
            tp = tp - floor(tp/2);

            pq.push(tp);
        }

        // add the updated values of piles and return answer.
        int ans = 0;
        while(!pq.empty()){
            int tp = pq.top();
            pq.pop();
            ans += tp;
        }

        return ans;

    }
};

/*
Algorithm:

1. Define a function called "minStoneSum" that takes in two parameters: a vector of integers named "piles" and an integer named "k." The function returns an integer.
2. Create a max heap (priority queue) named "pq" to store the elements from the "piles" vector.
3. Iterate over the elements in the "piles" vector using a for loop:
   - Insert each element into the priority queue using the "push" method.
4. Enter a while loop that continues until "k" is greater than 0 (to represent the number of stones you want to remove).
5. Inside the loop, retrieve the top (maximum) element from the priority queue using the "top" method and store it in an integer variable named "tp".
6. Remove the top element from the priority queue using the "pop" method.
7. Calculate the new value for "tp" by subtracting floor(tp/2) from "tp".
8. Push the updated value of "tp" back into the priority queue using the "push" method.
9. Decrement the value of "k" by 1.
10. Exit the while loop.
11. Declare a variable named "totalSum" and initialize it with 0. This variable will store the total sum of stones after removing the desired number of stones.
12. Enter a while loop that continues until the priority queue is empty.
13. Inside the loop, retrieve the top element from the priority queue using the "top" method and store it in the integer variable "tp".
14. Remove the top element from the priority queue using the "pop" method.
15. Add the value of "tp" to the "totalSum" variable.
16. Exit the while loop.
17. Return the value of "totalSum" as the result of the "minStoneSum" function.

*/
