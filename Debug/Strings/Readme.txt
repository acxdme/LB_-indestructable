# Supreme-Batch-Debug-Exercise-C++ (Week-5)

**NOTE: The code snippet given may be incomplete or have compile time, runtime or logical errors.**

**How to attempt Debugging Exercise?**

1. Copy the code to your code editor (e.g. VS Code).
2. Add relevant header files like “#include <iostream>” etc.
3. Run the code.
4. You will notice the expected output is not printing at the console.
5. Apply your smart coder mind to Debug the code.
6. **Warning**: Only see the solution after you have tried enough.

1. ******Debug the code.******

```cpp
void reverseWords(string s)
{
    vector<string> tmp;
    string str = "";
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ' ') {
            tmp.push_back(str);
            str = "";
        }
        else
            str += s[i];
    }
    tmp.push_back(str);
 return str;
}
```

[solution-1.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/abf6a8b1-3546-42d9-bda8-b0f66c4e8bab/solution-1.txt)

1. ******Debug the code. This code tries to find first maximum occurring character.******

```cpp
#include <bits/stdc++.h>
using namespace std;
 
char maxOccurring(char* str)
{
    int count[256] = {0};
    int max = INT_MAX;
    char answer;
 
    for (int i = 0; str[i] != '\0'; i++) {
        count[str[i]]++;
        if (max <= count[str[i]]) {
            max = count[str[i]];
            answer= str[i];
        }
    }
    return answer;
}

int main()
{
    char str[] = "sample string";
    cout << maxOccurring(str);
}
```

[solution-2.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/6bfbfe82-be52-43f0-b99f-17c6418370ba/solution-2.txt)

1. ******Debug the code. It tries to remove duplicates from the given string.******

```cpp
#include <bits/stdc++.h>
using namespace std;

char *removeDuplicate(char str[], int n) {
  // str is character array and n is the lenght of the character array
	int index = 0;
	for (int i=0; i<n; i++) {
		int j;
		for (j=0; j<i; j++)
			if (str[i] == str[j])
				str[index++] = str[i];
		}
		
	return str;
}
```

[solution-3.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/74d4a5f2-904b-4516-8fd2-2a03c264c849/solution-3.txt)

1. ******Debug the code. It tries to check if given string a Palindrome or not.******

```cpp
string isPalindrome(string S)
{
		int N = S.length();
    for (int i = 0; i < (N/2)-1; i++) {
		    if (S[i] != S[N-i]) {
            return "No";
        }
    }
    return "Yes";
}
```

[solution-4.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/c4e02d12-f347-4cb2-88e9-bd721bc01672/solution-4.txt)

1. ******Debug the code.******

```cpp
#include <iostream>  
using namespace std;  
int main() {  
    char char_array[] = {'L','A','K','S','H','A','Y'};  
    int array_size = sizeof(char_array);  
    string j = "";  
    int i;  
    for(i = 0; i < array_size; i++) {    
        j = j + char_array[i];  
    }  
    cout << j <<endl;  
}
```

[solution-5.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/9c4ba4cd-9b73-4d01-b62f-fac9f1b6882b/solution-5.txt)

1. ******Debug the code. This code attempt to reverse all words occur in a sentence. All words are space separated.******
