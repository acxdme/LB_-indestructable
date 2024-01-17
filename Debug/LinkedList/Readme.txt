// Debug-File

# Supreme-Batch-Debug-Exercise-C++ (Week-10)

**NOTE: The code snippet given may be incomplete or have compile time, runtime or logical errors.**

**How to attempt Debugging Exercise?**

1. Copy the code to your code editor (e.g. VS Code).
2. Add relevant header files like “#include <iostream>” etc.
3. Run the code.
4. You will notice the expected output is not printing at the console.
5. Apply your smart coder mind to Debug the code.
6. 
7. **Warning**: Only see the solution after you have tried enough.

1. ******Debug the code. Expected Output for the code is 1 2 3.******

```cpp
#include <iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
};

Node* head;

void insert(int x) {
  Node* temp = new Node;
  temp->data = x;
  temp->next = head;
  head = temp;
}

void print() {
  Node* temp = head;
  cout << "List: ";
  while (temp != NULL) {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main() {
  head = NULL;
  insert(1);
  insert(2);
  insert(3);
  print();
  return 0;
}
```

[solution-1.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/30623f2f-ce43-4492-b69e-c066322ff6cf/solution-1.txt)

1. ******Debug the code.******

```cpp
ListNode* middleNode(ListNode* head) {
        ListNode* last = head;
        ListNode* first = head;

        while (first->next != NULL && last != NULL) {
            last = last->next;
            first = first->next->next;
        }
    
        return last;
    }
```

[solution-2.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/f03311b2-501f-4ce4-a8b7-cd1ee7e62259/solution-2.txt)

1. ******Debug the code.******

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL)
            return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(slow != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow->next)
                return true;
        }
        
        return false;
    }
};
```

[solution-3.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/d2d038c7-015d-4a36-a2a4-97a955f6ca10/solution-3.txt)

1. **Debug the code. Task is to rotate the linked list counter-clockwise by k nodes**

```cpp
void rotate(Node* head, int k)
{
    if (k == 0)
        return;
    Node* current = head;
  
    int count = 1;
    while (count < k && current != NULL) {
        current = current->next;
        count++;
    }
  
    Node* kthNode = current;
    while (current->next != NULL)
        current = current->next;
  
    current->next = head;
    head = kthNode->next;
    kthNode->next = NULL;
}
```

[solution-4.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/99b5055e-dfbd-4995-857a-456b16418fc2/solution-4.txt)

1. **Debug the code.**
