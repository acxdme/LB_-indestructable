# Supreme-Batch-Debug-Exercise-C++ (Week-12)

**NOTE: The code snippet given may be incomplete or have compile time, runtime or logical errors.**

**How to attempt Debugging Exercise?**

1. Copy the code to your code editor (e.g. VS Code).
2. Add relevant header files like “#include <iostream>” etc.
3. Run the code.
4. You will notice the expected output is not printing at the console.
5. Apply your smart coder mind to Debug the code.
6. 
7. **Warning**: Only see the solution after you have tried enough.

1. **Debug the code. Queue using two stacks.**

```cpp
class MyQueue {
public:
    stack<int> s1;
    stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t= s2.top();
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    int peek() {
        while (!s1.empty()){
            s2.push(s1.top());
            s1.pop();
        }
        int t= s2.top();
				s2.pop();
        while (!s2.empty()){
            s1.push(s2.top());
            s2.pop();
        }
        return t;
    }
    
    bool empty() {
        return s1.empty();
    }
};
```

[solution-1.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3f85069d-9c07-4e54-973b-5c223e827fa7/solution-1.txt)

1. **Debug the code. Return index of first non-repeating character.**

```cpp
int firstUniqChar(string s) {
        vector<int> c(26,0);
        queue<char> q;
       
        for(auto i:s){
            c[i]++;
            q.push(i);
        }
        
        int idx=0;
      
        while(q.empty()){
            auto elem = q.front();
            q.pop();
            
            if(c[elem] != 1){
               idx++;
            }
        }
        return idx;
    }
```

[solution-2.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/3566003b-c7dd-4237-b0cc-216e6adbb2ae/solution-2.txt)

1. **Debug the code. Idea is to use stack involved in recursion to reverse the queue.**

```cpp
void reverseQueue(queue<int> &q) {
    q.pop();
    reverseQueue(q);
    q.push(q.front());
}
```

[solution-3.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/8ba37d32-00ac-461c-8eb7-04ff76b36b6a/solution-3.txt)

1. **Debug the code. Implement Queue using Linked List.**

```cpp
template<typename T>
class Queue {
    int capacity;
    int size;
    Node<T>* head;
    Node<T>* tail;
    public :
    Queue() {
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    void enqueue(T data) {
        Node<T>* temp = new Node<T>(data);
        if(isEmpty()){
            head = temp;
        }
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    
    int getSize() {
        return size;
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }
        return false;
    }
    
    T dequeue() {
        T data = head->data;
        head = head->next;
        return data;
    }
    
    T front()  {
        return head->data;
    }
};
```

[solution-4.txt](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/5e7c4502-9802-4bbd-be78-9c464ae7589a/solution-4.txt)

1. **Debug the code. Stack using two queues.**
