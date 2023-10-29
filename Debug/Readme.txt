# Supreme-Batch-Debug-Exercise-C++ (Week-7)

**NOTE: The code snippet given may be incomplete or have compile time, runtime or logical errors.**

**How to attempt Debugging Exercise?**

1. Copy the code to your code editor (e.g. VS Code).
2. Add relevant header files like “#include <iostream>” etc.
3. Run the code.
4. You will notice the expected output is not printing at the console.
5. Apply your smart coder mind to Debug the code.
6. **Warning**: Only see the solution after you have tried enough.

1. ******Debug the code. This is Tower of Hanoi Problem.******

```cpp
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod) {
    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, from_rod, to_rod);
}
```

[solution-1.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/35e9deba-35ed-439e-acf3-9cd90cd8d8e6/solution-1.txt)

1. ******Debug the code.******

```cpp
		bool isSafePlace(int n, vector<string>& nQueens, int row, int col){
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--, j--){
            if(nQueens[i][j] == 'Q'){
                return false;
            }
        }
        for(int i=row-1, j=col+1; i>=0 && j<n; i--, j++){
            if(nQueens[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void solveNQueens(int n, vector<vector<string>>& output, vector<string>& nQueens, int row){
        if(row == n){
            output.push_back(nQueens);
            return;
        }
        for(int col=0; col<n; col++){
            if(isSafePlace(n, nQueens, row, col)){
                nQueens[row][col] = 'Q';
                solveNQueens(n, output, nQueens, row+1);
            }
        }
    }
		vector<vector<string>> solve(int n) {
        vector<vector<string>> output;
        vector<string> nQueens(n , string(n, '.'));
        solveNQueens(n, output, nQueens, 0);
        return output;
    }
```

[solution-2.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/2ba0acba-8488-4ea1-86d4-71acf0bec0c3/solution-2.txt)

1. ******Debug the code. This code tries to replace “pi” with “3.14” in the string. For example, “xpix” changes to “x3.14x”.******

```cpp
void replacePi(char input[]) {
	if(input[0] == '\0'){
        return;
    }
    if(input[0] == 'p' && input[1] == 'i'){
        int n = strlen(input);
        int i = 2;
        for(i = n+1; i >= 2; i--){
            input[i] = input[i-2];
        }
        input[n+2] = '\0';
        input[0] = '3';
        input[1] = '.';
        input[2] = '1';
        input[3] = '4';
        replacePi(input + 1);
    }
    replacePi(input + 1);
}
```

[solution-3.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/92aba83a-7b88-4d79-a520-a4b9897fa1a5/solution-3.txt)

1. ******Debug the code. This code tries to implement string to integer converter.******

```cpp
int rec(char input[],int n){
    if(input[0] = '\0')
        return n;
    n = n * 10 + input[0];
    return rec(input + 1, n);
}

int stringToNumber(char input[]) {
    int n = 0;
    return rec(input, n);
}
```

[solution-4.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/e1bbb48c-9fa5-437a-b605-ed2bc2e97924/solution-4.txt)

1. **Debug the code. 
Question:
Given two integers M & N, calculate and return their multiplication using recursion. You can only use subtraction and addition for your calculation. No other operators are allowed.**

```cpp
int multiplyNumbers(int m, int n) {
    if(n < 0)
        return 0;
    return m + multiplyNumbers(m,n-1);
}
```

[solution-5.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c49457e6-b84f-4d71-a153-ea05f4ae3e50/solution-5.txt)
