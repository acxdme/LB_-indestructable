// codnin , find unique element in an array (each element occurs twice except once).
// concept of XOR brings us to the optimal solution.

//Time complexity : O(N)
//Space complexity : O(1)

int findUnique(int *arr, int size)
{
    int ans = 0;
    
    for(int i = 0 ;i < size; i++){
        ans = ans ^ arr[i];
    }
    
    return ans;
}
