# Supreme-Batch-Debug-Exercise-C++ (Week-3)

**NOTE: The code snippet given may be incomplete or have compile time, runtime or logical errors.**

**How to attempt Debugging Exercise?**

1. Copy the code to your code editor (e.g. VS Code).
2. Add relevant header files like “#include <iostream>” etc.
3. Run the code.
4. You will notice the expected output is not printing at the console.
5. Apply your smart coder mind to Debug the code.
6. **Warning**: Only see the solution after you have tried enough.

1. **This program declares an integer array of size 5 and initializes it with values 1, 2, 3, 4, and 5. Then, it attempts to print the elements of the array using a loop. However, there's an error in the loop that you need to debug. Can you find it and fix it?**

```cpp
#include <iostream>
using namespace std;

int main() {
   int arr[5] = {1, 2, 3, 4, 5};
   for(int i = 1; i <= 5; i++) {
      cout << arr[i] << " ";
   }  
   return 0;
}
```

[solution](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8d5316a0-8650-4282-ae15-887d9b9e9d6c/solution.txt)

1. **The above code uses the Boyer-Moore Voting Algorithm to find the majority element in the given `vector`of integers. Majority element is that element which appears more than n/2 times. However, there is a bug in the code that causes it to return an incorrect result for some inputs. Your task is to identify and fix the bug.  Hint: Incomplete code.**

```cpp
#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums) {
    int candidate, count = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (count == 0) {
            candidate = nums[i];
        }
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}

int main() {
    vector<int> nums = {1, 2, 3, 2, 2, 4, 2};
    cout << "The majority element is: " << majorityElement(nums) << endl;
    return 0;
}
```

[debug-2.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d87e477e-30ab-49af-84fe-1eb60470ff68/debug-2.txt)

1. **This code tries to move all negative numbers to one side but have some errors, can you spot those errors. Hint: Incomplete conditions applied.**

```cpp
#include<iostream>
using namespace std;
void moveNegative(int arr[], int n){
    int i=0, j=n-1;
    while(i<j){
        while(arr[i]<0){ // swap when a positive element is encountered
            i++;
        }
        while(arr[j]>0){ // swap when a negative element is encountered
            j--;
        }
        swap(arr[i], arr[j]); // swap the elements
    }
}
int main(){
    int n = 5;
    int arr[n] = {2, -3, -1, 5, -4};
    moveNegative(arr, n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
```

[debug-3.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f9e49599-2110-404c-b566-a80da233e78b/debug-3.txt)

1. **********************************This code attempts to print elements (only once) which appear more than one time. Can you spot the error in the code:**********************************

```cpp
#include<iostream>
#include<cstring>
using namespace std;

void printDuplicates(int arr[], int n){
    int freq[n+1];
    memset(freq, 0, sizeof(freq)); // initialize the frequency array to 0
    bool flag = false; // added a flag to check if there are no duplicate elements
    for(int i=0;i<=n;i++){
        freq[arr[i]]++;
        if(freq[arr[i]] > 1){
            flag = true;
            cout<<arr[i]<<" ";
        }
    }
    if(!flag){
        cout<<"No duplicate elements";
    }
}

int main(){
    int n = 6;
    int arr[n] = {3, 2, 1, 2, 2, 3};
    printDuplicates(arr, n);
    return 0;
}
```

[debug-4.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6a7f929d-560c-46f2-b000-b3647193cb38/debug-4.txt)

1. **************This code attempts to rotate a matrix by 60 degrees. Debug it.**************
